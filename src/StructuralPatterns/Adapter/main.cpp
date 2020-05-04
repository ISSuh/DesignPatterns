/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "adapter.hpp"

int main() {
    std::cout << "Design Patterns - Adapter Pattern" << std::endl;

    ImgaeViwer imageViwer("AdapterStcucturePicture");

    imageViwer.setViwer();
    imageViwer.show();
    imageViwer.clear();
}
