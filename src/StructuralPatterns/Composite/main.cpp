/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

#include "composite.hpp"

int main() {
  std::cout << "Design Patterns - Compositr Pattern\n" << std::endl;

  // Composite 객체 생성
  MediaWindow* mainWindow = new MediaWindow("MyMediaWindow");
  VideoPlayer* videoPlayer = new VideoPlayer("MyVideoWindow");
  ImageWindow* imageWindow = new ImageWindow("MyImageWindow");

  // Leaf 객체 생성
  TitleBar* mainTitleBar = new TitleBar("MyMediaWindowTitleBar");
  TitleBar* videoTitleBar = new TitleBar("MyVideoWindowTitleBar");
  TitleBar* imageTitleBar = new TitleBar("MyImageWindowTitleBar");

  // Leaf객체를 Composite의 자식으로 구성
  mainWindow->add(mainTitleBar);
  mainWindow->add(new MenuBar("MyMediaWindowMenuBar"));

  videoPlayer->add(new MenuBar("MyVideoWindowMenubar"));
  videoPlayer->add(videoTitleBar);

  imageWindow->add(imageTitleBar);

  // Composite을 Composite의 자식으로 구성
  mainWindow->add(videoPlayer);
  mainWindow->add(imageWindow);

  std::cout << "Component Lists : " << std::endl;
  mainWindow->printElementList();
  std::cout << std::endl;

  mainWindow->remove();

  std::cout << "Component Lists : " << std::endl;
  mainWindow->printElementList();
}
