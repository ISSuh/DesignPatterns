/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "factory_method.hpp"

int main() {
    std::cout << "Design Patterns - Factory Method Pattern" << std::endl;

    DisplayCreator<ImageDisplay> creator;
    auto imageDisplayer = creator.createDisplay();

    imageDisplayer->show();
}
