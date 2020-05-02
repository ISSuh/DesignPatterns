/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "prototype.hpp"

int main() {
    std::cout << "Design Patterns - ProtoType Pattern" << std::endl;

    Position pos;
    pos.x = 100;
    pos.y = 100;

    GrapicFactory gfactory;

    gfactory.setGraphicType(GRAPHIC_TYPE::CIRCLE);
    Graphic* circle = gfactory.createGraphic(pos);
    circle->draw();

    gfactory.setGraphicType(GRAPHIC_TYPE::TRIANGLE);
    Graphic* triangle = gfactory.createGraphic(pos);
    triangle->draw();
}
