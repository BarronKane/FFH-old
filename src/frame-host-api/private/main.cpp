#include <iostream>

#include "factorio-frame-host.h"

// C++17 quick constexpr lambda test.
constexpr int addOne(int n) {
    return [n] {return n + 1; }();
}

int main(int argc, char *argv[])
{
    static_assert(addOne(1) == 2);
}