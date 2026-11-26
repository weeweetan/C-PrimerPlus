#include "dma.h"

#include <cstdlib>
#include <iostream>
#include <new>
#include <sstream>
#include <string>

#define CHECK(condition) do { if (!(condition)) { \
    std::cerr << "Line " << __LINE__ << ": " << #condition << '\n'; \
    std::exit(EXIT_FAILURE); \
} } while (false)

static int allocations_before_failure = -1;

void *operator new[](std::size_t size)
{
    if (allocations_before_failure == 0) {
        allocations_before_failure = -1;
        throw std::bad_alloc();
    }
    if (allocations_before_failure > 0) --allocations_before_failure;
    return ::operator new(size);
}

void operator delete[](void *pointer) noexcept
{
    ::operator delete(pointer);
}

template <typename T>
static std::string render(const T &value)
{
    std::ostringstream output;
    output << value;
    return output.str();
}

template <typename T>
static void assignment_failure(T &destination, const T &source, int before_failure)
{
    const std::string original = render(destination);
    const std::string expected = render(source);
    allocations_before_failure = before_failure;
    bool threw = false;
    try { destination = source; }
    catch (const std::bad_alloc &) { threw = true; }
    allocations_before_failure = -1;
    CHECK(threw);
    CHECK(render(destination) == original);
    CHECK(render(source) == expected);
    destination = source;
    CHECK(render(destination) == expected);
}

int main(int argc, char **argv)
{
    CHECK(argc == 2);
    const std::string test = argv[1];
    if (test == "basic") {
        baseDMA base("first", 1), other("second", 2);
        base = other;
        CHECK(render(base) == render(other));
        baseDMA &base_alias = base;
        base = base_alias;
        CHECK(render(base) == render(other));
        hasDMA derived("initial", "old label", 3);
        hasDMA copy(derived);
        CHECK(render(copy) == render(derived));
        derived = hasDMA("updated", "new label", 4);
        CHECK(render(copy) != render(derived));
        hasDMA &derived_alias = derived;
        derived = derived_alias;
        CHECK(render(derived).find("updated") != std::string::npos);
    } else if (test == "base-failure") {
        baseDMA destination("original", 1), source("replacement", 2);
        assignment_failure(destination, source, 0);
    } else if (test == "style-failure") {
        hasDMA destination("original style", "old label", 1);
        hasDMA source("replacement style", "new label", 2);
        assignment_failure(destination, source, 0);
    } else if (test == "base-part-failure") {
        hasDMA destination("original style", "old label", 1);
        hasDMA source("replacement style", "new label", 2);
        assignment_failure(destination, source, 1);
    } else {
        return EXIT_FAILURE;
    }
}
