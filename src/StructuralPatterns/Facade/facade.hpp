/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <vector>
#include <memory>
#include <queue>

/**
 * @brief SubSystem - Buffer
 * @details 추후 서비스가 추가될 인터페이스 정의
 */
class Buffer {
 public:
  void push(uint8_t data) { m_buffer.push(data); }
  
  uint8_t pop() { 
    auto temp = m_buffer.front();
    m_buffer.pop();
    return temp;
  }

 private:
  std::queue<uint8_t> m_buffer;
};

/**
 * @brief SubSystem - Viewer
 * @details 추후 서비스가 추가될 인터페이스 정의
 */
class Viewer {
 public:
  Viewer(int width, int height, Buffer& buf) : m_width(width), 
                                               m_height(height),
                                               m_buffer(buf) 
  {
    std::cout << "Set Viewer Size " << m_width << "x" << m_height << std::endl;
  } 

  void view() {
    auto image = m_buffer.pop();
    std::cout << "Viewing - " << image << std::endl;
  }

 private:
  const int m_width;
  const int m_height;
  Buffer& m_buffer; 
};

/**
 * @brief SubSystem - Image
 * @details 추후 서비스가 추가될 인터페이스 정의
 */
class Image {
 public:
  Image(Buffer& buf) : m_buffer(buf) {}

  void open(const std::string& imagePath) {
    std::cout << "Open Image : " << imagePath << std::endl;
  }

  void getImage() {
    m_buffer.push(50);
  }
  
  void close() {
    std::cout << "Close" << std::endl;
  }

 private:
  Buffer& m_buffer;
};

/**
 * @brief Facade - ImageViwer
 * @details SybSystem을 기반으로 통합 인터페이스를 구성
 */
class ImageViwer {
 public:
  void init() {
    m_buffer = new Buffer();
    m_viewer = new Viewer(100,100, *m_buffer);
    m_image = new Image(*m_buffer);
  }

  void imageView() {
    m_image->open("path/image");
    m_image->getImage();

    m_viewer->view();

    m_image->close();
  }

 private:
  Viewer* m_viewer = nullptr;
  Buffer* m_buffer = nullptr;
  Image* m_image = nullptr;
};
