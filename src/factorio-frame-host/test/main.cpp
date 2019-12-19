#include <iostream>
#include <string>

#include "factorio-frame-host.h"

int main()
{
    factorio ffh;

    ffh.test();

    // Hack to fake a pause.
    std::string wait;
    std::cout << "Press enter to continue...";
    std::getline(std::cin, wait);
}
