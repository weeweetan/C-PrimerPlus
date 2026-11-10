#include "MyArray.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

#define CHECK(condition) do { if (!(condition)) { \
    std::cerr << "Line " << __LINE__ << ": " << #condition << '\n'; \
    std::exit(EXIT_FAILURE); \
} } while (false)

struct Tracked {
    static int live;
    static int assignments_until_throw;
    static int defaults_until_throw;
    int value;

    Tracked() : value(0)
    {
        if (defaults_until_throw == 0) throw std::runtime_error("default construction");
        if (defaults_until_throw > 0) --defaults_until_throw;
        ++live;
    }
    Tracked(const Tracked &other) : value(other.value) { ++live; }
    ~Tracked() { --live; }
    Tracked &operator=(const Tracked &other)
    {
        value = other.value; // A failing assignment may already have changed this slot.
        if (assignments_until_throw == 0) throw std::runtime_error("element assignment");
        if (assignments_until_throw > 0) --assignments_until_throw;
        return *this;
    }
};
int Tracked::live = 0;
int Tracked::assignments_until_throw = -1;
int Tracked::defaults_until_throw = -1;

static void append(MyArray<Tracked> &array, int value)
{
    Tracked element;
    element.value = value;
    array.Push_Back(element);
}

static void basic()
{
    MyArray<int> array(2);
    CHECK(array.getSize() == 0 && array.getCapacity() == 2);
    array.Push_Back(11); array.Push_Back(22); array.Push_Back(33);
    const MyArray<int> &view = array;
    CHECK(view.getSize() == 2 && view.getCapacity() == 2 && view[0] == 11 && view[1] == 22);
    array.Pop_Back(); CHECK(array.getSize() == 1 && array[0] == 11);
    array.Pop_Back(); array.Pop_Back(); CHECK(array.getSize() == 0);
    MyArray<int> zero(0);
    zero.Push_Back(1); zero.Pop_Back();
    CHECK(zero.getSize() == 0 && zero.getCapacity() == 0);
    bool rejected = false;
    try { MyArray<int> invalid(-1); }
    catch (const std::invalid_argument &) { rejected = true; }
    CHECK(rejected);
}

static void copy()
{
    MyArray<std::string> source(3);
    source.Push_Back("alpha"); source.Push_Back("beta");
    MyArray<std::string> constructed(source);
    source[0] = "changed source";
    CHECK(constructed.getSize() == 2 && constructed.getCapacity() == 3);
    CHECK(constructed[0] == "alpha" && constructed[1] == "beta");
    MyArray<std::string> assigned(1), chained(0);
    assigned.Push_Back("old");
    CHECK(&(assigned = constructed) == &assigned);
    CHECK(&(chained = assigned = constructed) == &chained);
    CHECK(assigned.getCapacity() == 3 && assigned.getSize() == 2 && chained[1] == "beta");
    assigned[1] = "changed copy";
    CHECK(constructed[1] == "beta" && chained[1] == "beta");
    MyArray<std::string> empty(0);
    assigned = empty;
    CHECK(assigned.getSize() == 0 && assigned.getCapacity() == 0);
    MyArray<std::string> reserved(5);
    empty = reserved;
    CHECK(empty.getSize() == 0 && empty.getCapacity() == 5);
}

static void self_assignment()
{
    {
        MyArray<Tracked> array(3);
        append(array, 7); append(array, 8);
        int before = Tracked::live;
        Tracked::assignments_until_throw = 0;
        MyArray<Tracked> &alias = array;
        CHECK(&(array = alias) == &array);
        CHECK(array.getSize() == 2 && array.getCapacity() == 3);
        CHECK(array[0].value == 7 && array[1].value == 8 && Tracked::live == before);
        Tracked::assignments_until_throw = -1;
        MyArray<Tracked> empty(0);
        MyArray<Tracked> &empty_alias = empty;
        empty = empty_alias;
        CHECK(empty.getSize() == 0 && empty.getCapacity() == 0);
    }
    CHECK(Tracked::live == 0);
}

static void copy_construction_failure()
{
    {
        MyArray<Tracked> source(4);
        append(source, 10); append(source, 20); append(source, 30);
        int before = Tracked::live;
        Tracked::assignments_until_throw = 1;
        bool threw = false;
        try { MyArray<Tracked> failed(source); }
        catch (const std::runtime_error &) { threw = true; }
        CHECK(threw && Tracked::live == before);
        CHECK(source.getSize() == 3 && source[0].value == 10 && source[2].value == 30);
        Tracked::assignments_until_throw = -1;
        MyArray<Tracked> recovered(source);
        CHECK(recovered.getSize() == 3 && recovered[1].value == 20);
    }
    CHECK(Tracked::live == 0);
}

static void assignment_failure()
{
    {
        MyArray<Tracked> source(5), destination(2);
        append(source, 10); append(source, 20); append(source, 30);
        append(destination, 7); append(destination, 8);
        int before = Tracked::live;
        Tracked::assignments_until_throw = 1;
        bool threw = false;
        try { destination = source; }
        catch (const std::runtime_error &) { threw = true; }
        CHECK(threw && Tracked::live == before);
        CHECK(destination.getCapacity() == 2 && destination.getSize() == 2);
        CHECK(destination[0].value == 7 && destination[1].value == 8);
        CHECK(source.getCapacity() == 5 && source.getSize() == 3 && source[1].value == 20);
        Tracked::assignments_until_throw = -1;
        destination = source;
        CHECK(destination.getSize() == 3 && destination.getCapacity() == 5 && destination[2].value == 30);
    }
    CHECK(Tracked::live == 0);
}

static void default_construction_failure()
{
    {
        MyArray<Tracked> source(4), destination(2);
        append(source, 10); append(source, 20); append(destination, 7);
        int before = Tracked::live;
        Tracked::defaults_until_throw = 1;
        bool threw = false;
        try { destination = source; }
        catch (const std::runtime_error &) { threw = true; }
        CHECK(threw && Tracked::live == before);
        CHECK(destination.getCapacity() == 2 && destination.getSize() == 1 && destination[0].value == 7);
        Tracked::defaults_until_throw = -1;
        destination = source;
        CHECK(destination.getSize() == 2 && destination[1].value == 20);
    }
    CHECK(Tracked::live == 0);
}

static void append_failure()
{
    {
        MyArray<Tracked> array(3);
        append(array, 11);
        Tracked next;
        next.value = 22;
        int before = Tracked::live;
        Tracked::assignments_until_throw = 0;
        bool threw = false;
        try { array.Push_Back(next); }
        catch (const std::runtime_error &) { threw = true; }
        CHECK(threw && Tracked::live == before && array.getSize() == 1 && array[0].value == 11);
        Tracked::assignments_until_throw = -1;
        array.Push_Back(next);
        CHECK(array.getSize() == 2 && array[1].value == 22);
    }
    CHECK(Tracked::live == 0);
}

int main(int argc, char **argv)
{
    if (argc != 2) return 2;
    const std::string name(argv[1]);
    if (name == "basic") basic();
    else if (name == "copy") copy();
    else if (name == "self-assignment") self_assignment();
    else if (name == "copy-construction-failure") copy_construction_failure();
    else if (name == "assignment-failure") assignment_failure();
    else if (name == "default-construction-failure") default_construction_failure();
    else if (name == "append-failure") append_failure();
    else return 2;
    std::cout << name << ": passed\n";
}
