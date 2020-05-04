/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "bridge.hpp"

int main() {
    std::cout << "Design Patterns - Bridge Pattern" << std::endl << std::endl;

    NativeWindow nativeWindow;
    nativeWindow.initWindow(RendererType::IMAGE);
    nativeWindow.displayWindow();

    VirtualWindow virtualWindow;
    virtualWindow.initWindow(RendererType::VIDEO);
    virtualWindow.displayWindow();
}
