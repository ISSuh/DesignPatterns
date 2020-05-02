/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

/**
 * @brief Product - Display
 * @details
 */
class Display {
 public:
    virtual ~Display() = default;
    virtual void show() = 0;

 protected:
    Display() = default;
};

/**
 * @brief ConcreteProduct - WINDisplay
 * @details
 */
class ImageDisplay : public Display {
 public:
    void show() override {
        std::cout << "Image Display show\n";
    }
};

/**
 * @brief ConcreteProduct - OSXDisplay
 * @details
 */
class VideoDisplay : public Display {
 public:
    void show() override {
        std::cout << "Video Display show\n";
    }
};

/**
 * @brief ConcreteProduct - OSXDisplay
 * @details
 */
class DummyDisplay : public Display {
 public:
    void show() override {
        std::cout << "Dummy Display show\n";
    }
};

/**
 * @brief Creator - Creator
 * @details
 */
template<class T>
class Creator {
 public:
    virtual ~Creator() = default;

    // Factory Method
    virtual std::unique_ptr<T> createDisplay() const = 0;

 protected:
    Creator() = default;
};

/**
 * @brief DisplayCreator - Creator
 * @details
 */
template<class T>
class DisplayCreator  : public Creator<T> {
 public:
    // override Factory Method
    std::unique_ptr<T> createDisplay() const override {
        return std::unique_ptr<T>(new T());
    }
};
