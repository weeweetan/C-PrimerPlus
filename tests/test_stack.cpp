#include "stacktp.h"
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#define CHECK(condition) do { if (!(condition)) { \
    std::cerr << "Line " << __LINE__ << ": " << #condition << '\n'; \
    std::exit(EXIT_FAILURE); \
} } while (false)

struct Element {
    static bool fail_assignment;
    int value;

    explicit Element(int v = 0) : value(v) {}
    Element &operator=(const Element &other)
    {
        value = other.value; // A throwing assignment can already have changed its destination.
        if (fail_assignment) throw std::runtime_error("element assignment");
        return *this;
    }
};
bool Element::fail_assignment = false;

static void basic()
{
    Stack<int> stack;
    int output = -1;
    CHECK(stack.istempty() && !stack.isfull());
    CHECK(!stack.pop(output) && output == -1);
    for (int i = 0; i < 10; ++i) CHECK(stack.push(i));
    CHECK(stack.isfull() && !stack.istempty());
    CHECK(!stack.push(99) && stack.isfull());
    for (int i = 9; i >= 0; --i) {
        CHECK(stack.pop(output) && output == i);
        CHECK(!stack.isfull());
    }
    CHECK(stack.istempty());
    CHECK(!stack.pop(output) && output == 0);
    CHECK(stack.push(42) && stack.pop(output) && output == 42);

    Stack<std::string> strings;
    CHECK(strings.push("first") && strings.push("second"));
    std::string text;
    CHECK(strings.pop(text) && text == "second");
    CHECK(strings.pop(text) && text == "first" && strings.istempty());
}

static void fill(Stack<Element> &stack, int count)
{
    for (int i = 0; i < count; ++i) CHECK(stack.push(Element(i)));
}

static void drain(Stack<Element> &stack, int count)
{
    Element output(-1);
    for (int i = count - 1; i >= 0; --i) {
        CHECK(stack.pop(output) && output.value == i);
    }
    CHECK(stack.istempty() && !stack.pop(output));
}

static void push_failure()
{
    for (int count : {0, 5, 9}) {
        Stack<Element> stack;
        fill(stack, count);
        Element next(count);
        Element::fail_assignment = true;
        bool threw = false;
        try { stack.push(next); }
        catch (const std::runtime_error &) { threw = true; }
        Element::fail_assignment = false;
        CHECK(threw);
        CHECK(stack.istempty() == (count == 0));
        CHECK(!stack.isfull());
        CHECK(next.value == count);
        CHECK(stack.push(next)); // Retry must use the same free slot.
        drain(stack, count + 1);
    }
    Stack<Element> full;
    fill(full, 10);
    Element::fail_assignment = true;
    CHECK(!full.push(Element(99))); // Full rejection must not attempt an assignment.
    Element::fail_assignment = false;
    drain(full, 10);
}

static void pop_failure()
{
    for (int count : {1, 5, 10}) {
        Stack<Element> stack;
        fill(stack, count);
        Element output(-1);
        Element::fail_assignment = true;
        bool threw = false;
        try { stack.pop(output); }
        catch (const std::runtime_error &) { threw = true; }
        Element::fail_assignment = false;
        CHECK(threw);
        CHECK(!stack.istempty());
        CHECK(stack.isfull() == (count == 10));
        // The caller's output may have changed; the top element must remain available.
        CHECK(stack.pop(output) && output.value == count - 1);
        CHECK(stack.push(output));
        drain(stack, count);
    }
    Stack<Element> empty;
    Element output(123);
    Element::fail_assignment = true;
    CHECK(!empty.pop(output) && output.value == 123);
    Element::fail_assignment = false;
}

static void model()
{
    Stack<int> stack;
    std::vector<int> expected;
    std::uint32_t state = 123456789;
    for (int i = 0; i < 5000; ++i) {
        state = state * 1664525u + 1013904223u;
        if ((state >> 16) & 1u) {
            const bool accepted = expected.size() < 10;
            CHECK(stack.push(i) == accepted);
            if (accepted) expected.push_back(i);
        } else {
            int output = -1;
            const bool available = !expected.empty();
            CHECK(stack.pop(output) == available);
            if (available) {
                CHECK(output == expected.back());
                expected.pop_back();
            } else CHECK(output == -1);
        }
        CHECK(stack.istempty() == expected.empty());
        CHECK(stack.isfull() == (expected.size() == 10));
    }
    int output = -1;
    while (!expected.empty()) {
        CHECK(stack.pop(output) && output == expected.back());
        expected.pop_back();
    }
    CHECK(stack.istempty());
}

int main(int argc, char **argv)
{
    if (argc != 2) return 2;
    const std::string name(argv[1]);
    if (name == "basic") basic();
    else if (name == "push-failure") push_failure();
    else if (name == "pop-failure") pop_failure();
    else if (name == "model") model();
    else return 2;
    std::cout << name << ": passed\n";
}
