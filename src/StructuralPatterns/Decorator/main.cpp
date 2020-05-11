/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "decorator.hpp"

int main() {
  std::cout << "Design Patterns - Decorator Pattern\n" << std::endl;

  Viewer* viwer = dynamic_cast<Viewer*>(new BasicViewer());
  viwer = dynamic_cast<Viewer*>(new CameraSensor(viwer));
  viwer->view();

  viwer = dynamic_cast<Viewer*>(new LidarSensor(viwer));
  viwer->view();
}
