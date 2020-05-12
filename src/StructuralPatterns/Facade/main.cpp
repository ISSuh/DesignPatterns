/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "facade.hpp"

int main() {
  std::cout << "Design Patterns - Facade Pattern\n" << std::endl;

  ImageViwer imageViewer;

  imageViewer.init();
  imageViewer.imageView();
}
