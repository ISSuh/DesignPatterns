/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

enum class RendererType : uint8_t {
    IMAGE,
    VIDEO
};

/**
 * @brief Implementor - Render
 * @details Abstraction의 세부 행위의 인터페이스 정의
 */
class Render {
 public:
    virtual ~Render() = default;
    virtual void rendering() const = 0;
};

/**
* @brief ConcreteImplementor - ImageRender
* @details Implementor를 상속받아 Abstraction의 세부 행위의 인터페이스를 구현
*/
class ImageRender : public Render {
public:
  void rendering() const override {
    std::cout << "Start Image rendering\n" << std::endl;
  }
};

/**
* @brief ConcreteImplementor - VideoRender
* @details Implementor를 상속받아 Abstraction의 세부 행위의 인터페이스를 구현
*/
class VideoRender : public Render {
public:
  void rendering() const override {
    std::cout << "Start Video rendering\n" << std::endl;
  }
};

/**
 * @brief Abstraction - Window
 * @details 추상적 개념의 인터페이스를 제공
 */
class Window {
 public:
    virtual ~Window() = default;

    // Window가 처리할 요청
    virtual void initWindow(RendererType type) = 0;

    // 구현 클래스를 이용하여 처리할 요청
    virtual void displayWindow() {
        std::shared_ptr<Render> render = getRenderImpl();
        
        render->rendering();
    }
 
 protected:
    virtual std::shared_ptr<Render> getRenderImpl() {
        if(!m_render){
            switch (m_rendererType) {
            case RendererType::IMAGE :
                m_render = std::make_shared<ImageRender>();
                break;
            case RendererType::VIDEO :
                m_render = std::make_shared<VideoRender>();
                break;
            }
        }

        return m_render;
    }

    void setRendererType(RendererType rendererType) {
        m_rendererType = rendererType;
    }

 private:
    std::shared_ptr<Render> m_render = nullptr;
    RendererType m_rendererType;
};

/**
 * @brief RefinedAbstraction - NativeWindow
 * @details 추상적 개념의 인터페이스를 확장 하여,
 *          다른 종류의 window 정의하여 추가적인 서비스를 제공
 */
class NativeWindow : public Window {
 public:
    NativeWindow() {
        std::cout << "Create Native Window\n";
    }

    void initWindow(RendererType type) override {
        std::cout << "Initialize Native Window - ";

        switch(type) {
        case RendererType::IMAGE :
            std::cout << "Image Renderer\n";
            break;
        case RendererType::VIDEO :
            std::cout << "Video Renderer\n";
            break;
        }

        setRendererType(type);
    }
};

/**
 * @brief RefinedAbstraction - VirtualWindow
 * @details 추상적 개념의 인터페이스를 확장 하여,
 *          다른 종류의 window 정의하여 추가적인 서비스를 제공
 */
class VirtualWindow : public Window {
 public:
    VirtualWindow() {
        std::cout << "Create Virtual Window\n";
    }

    void initWindow(RendererType type) override {
        std::cout << "Initialize Virtaul Window - ";

        switch(type) {
        case RendererType::IMAGE :
            std::cout << "Image Renderer\n";
            break;
        case RendererType::VIDEO :
            std::cout << "Video Renderer\n";
            break;
        }

        setRendererType(type);
    }
};
