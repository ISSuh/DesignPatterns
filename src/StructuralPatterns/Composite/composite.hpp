/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief Component - Window
 * @details
 */
class Window {
 public:
  virtual ~Window() = default;

  // 구성요소들의 공통 인터페이스 정의
  virtual const std::string& getName() const { return m_name; }
  virtual void printElementList() = 0;

  // 자식요소 관리를 위한 인터페이스 정의
  virtual void add(Window* window) {};
  virtual void remove() {};

 protected:
  Window(const std::string& name) : m_name(name) {};

 private:
    const std::string m_name;
};

/**
* @brief Composite - MediaWindow
* @details 하위 구성요소를 가지지면서 관련 인터페이스를 구현 및 정의
*/
class MediaWindow : public Window {
public:
  MediaWindow(const std::string& name) : Window(name) {};
  virtual ~MediaWindow() {
    for(auto& e : m_elements){
      delete e;
    }
  }

  // 구성요소들의 공통 인터페이스 구현
  void printElementList() override {
    std::cout << this->getName() << std::endl;

    for(const auto& e : m_elements){
      e->printElementList();
    }
  }

  // 자식요소 관리를 위한 인터페이스 구현
  void add(Window* window) override { m_elements.push_back(window); }
  void remove() override { m_elements.pop_back(); }

private:
  std::vector<Window*> m_elements;
};

/**
* @brief Composite - ImageWindow
* @details 하위 구성요소를 가지지면서 관련 인터페이스를 구현 및 정의
*/
class ImageWindow : public Window {
public:
  ImageWindow(const std::string& name) : Window(name) {};
  virtual ~ImageWindow() {
    for(auto& e : m_elements){
      delete e;
    }
  }

  // 구성요소들의 공통 인터페이스 구현
  void printElementList() override {
    std::cout << this->getName() << std::endl;

    for(const auto& e : m_elements){
      e->printElementList();
    }
  }

  // 자식요소 관리를 위한 인터페이스 구현
  void add(Window* window) override { m_elements.push_back(window); }
  void remove() override { m_elements.pop_back(); }

private:
  std::vector<Window*> m_elements;
};

/**
* @brief Leaf - TitleBar
* @details 자식이 없으며, Component의 인터페이스를 자신에 맞게 구현
*/
class TitleBar : public Window{
public:
  TitleBar(const std::string& name) : Window(name) {}
  virtual ~TitleBar() {}

  // 구성요소들의 공통 인터페이스 구현
  void printElementList() override { std::cout <<  getName() << std::endl; }
};

/**
* @brief Leaf - MenuBar
* @details 자식이 없으며, Component의 인터페이스를 자신에 맞게 구현
*/
class MenuBar : public Window{
public:
  MenuBar(const std::string& name) : Window(name) {}
  virtual ~MenuBar() {}

  // 구성요소들의 공통 인터페이스 구현
  void printElementList() override { std::cout <<  getName() << std::endl; }
};

/**
* @brief Leaf - VideoPlayer
* @details 자식이 없으며, Component의 인터페이스를 자신에 맞게 구현
*/
class VideoPlayer : public MediaWindow{
public:
  VideoPlayer(const std::string& name) : MediaWindow(name) {}
  virtual ~VideoPlayer() {}

  // 구성요소들의 공통 인터페이스 구현
  void printElementList() override { std::cout <<  getName() << std::endl; }
};