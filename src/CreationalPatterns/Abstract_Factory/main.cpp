/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "abstract_factory.hpp"

int main() {
    std::cout << "Design Patterns - Abstract Factory Pattern" << std::endl;

    std::unique_ptr<AbstractFactory> factory(
                dynamic_cast<AbstractFactory*>(new Factory_1()));

    AbstractProductA* productA = nullptr;
    AbstractProductB* productB = nullptr;

    productA = factory->cretaeProductA();
    productB = factory->cretaeProductB();

    productA->printA();
    productB->printB();
}
