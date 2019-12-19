#include <iostream>
#include <string>

#include <boost/chrono.hpp>

#include "factorio-frame-host.h"

void factorio::test()
{
    std::cout << "Hello, world!" << '\n';
    std::cout << boost::chrono::high_resolution_clock::now() << '\n';
}
