/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>

#include "singleton.hpp"

int main() {
    std::cout << "Design Patterns - Singleton Pattern" << std::endl;

    std::cout << "My Name : "
        << MyClass::getInstence().getName()
        << std::endl;

    MyClass::getInstence().setName("Test");

    std::cout << "My Name : "
        << MyClass::getInstence().getName()
        << std::endl;
}
