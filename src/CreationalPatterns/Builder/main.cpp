/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "builder.hpp"

int main() {
    std::cout << "Design Patterns - Builder Pattern" << std::endl;

    PeopleDirector director;
    auto programmerBuilder = std::unique_ptr<Builder>(new ProgrammerBuilder());
    auto salesManBuilder = std::unique_ptr<Builder>(new SalesManBuilder());

    director.setBuilder(std::move(programmerBuilder));
    auto programmer = director.constructPeople("Suh", 30);
    programmer->printInfo();

    std::cout << std::endl;

    director.setBuilder(std::move(salesManBuilder));
    auto salesMan = director.constructPeople("John", 42);
    salesMan->printInfo();
}
