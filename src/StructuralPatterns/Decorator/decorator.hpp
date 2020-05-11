/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief Component - Viewer
 * @details 추후 서비스가 추가될 인터페이스 정의
 */
class Viewer {
 public:
  virtual ~Viewer() {}

  virtual void view() = 0;
};

/**
 * @brief ConcreteComponent - SensorViewer
 * @details 인터페이스의 기본 행동 구현
 */
class BasicViewer : public Viewer {
 public:
  virtual ~BasicViewer() {}

  void view() override {
    std::cout << "Viewing!\n\n";
  }
};

/**
 * @brief Decorator - SensorViewer
 * @details 기존의 인터페이스에 동작을 추가하기 위해 중간 Decorator 클래스 정의
 */
class SensorViewer : public Viewer{
 public:
  SensorViewer(Viewer* viewer) : m_viewer(viewer) {}
  virtual ~SensorViewer() {}

  void view() override {
    m_viewer->view();
  }

 private:
  Viewer* m_viewer = nullptr;
};


/**
 * @brief ConcreteDecorator - CameraSensor
 * @details 새롭게 추가할 행동 정의
 */
class CameraSensor : public SensorViewer{
 public:
  CameraSensor(Viewer* viewer) : SensorViewer(viewer) {}
  virtual ~CameraSensor() {}

  void view() override {
    setImage();
    SensorViewer::view();
  }

 private:
  void setImage() {
    std::cout << "Get Camera Sensor's IMAGE\n";
  }
};

/**
 * @brief ConcreteDecorator - CameraSensor
 * @details 새롭게 추가할 행동 정의
 */
class LidarSensor : public SensorViewer{
 public:
  LidarSensor(Viewer* viewer) : SensorViewer(viewer) {}
  virtual ~LidarSensor() {}

  void view() override {
    setPointCloud();
    SensorViewer::view();
  }

 private:
  void setPointCloud() {
    std::cout << "Set Lidar Sensor's Point Cloud\n";
  }
};
