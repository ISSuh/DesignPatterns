/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

/**
 * @brief Taget - People
 * @details 재정의할 interface를 가진 class
 */
class Viwer {
 public:
    Viwer() {
        std::cout << "Create Viwer\n";
    }

    virtual ~Viwer() = default;

    virtual void setViwer() {
        std::cout << "Set Dummy Viwer\n";

        setShowingData("Dummy");
    }

    virtual void clear() {
        std::cout << "Clear Dummy Viwer\n";
    }

    virtual void show() {
        std::cout << "Show " << getShowingData() << " Viwer\n";
    }

 protected:
    void setShowingData(const std::string& data) { m_data = data; }
    const std::string& getShowingData() const { return m_data; }

 private:
    std::string m_data;
};

/**
 * @brief Adaptee - Job
 * @details 사용할 함수를 가진 class
 */
class Image {
 public:
    Image() {
        std::cout << "Create Image\n";
    }

    virtual ~Image() = default;

    virtual void openImage(const std::string& filePath) {
        std::cout << "Open " << filePath << std::endl;
        m_imageData = filePath + "_IMAGE";
    }

    virtual void closeImage() {
        std::cout << "Close Image File\n";
        m_imageData.clear();
    }

    const std::string& getImage() const { return m_imageData; }

 private:
    std::string m_imageData;
};

/**
* @brief Adapter - TextShape
*/
class ImgaeViwer : public Viwer,
                          Image {

 public:
    ImgaeViwer(const std::string& filePath) : m_filePath(filePath) {
        std::cout << "Create ImageViwer\n";
    }

    void setViwer() override {
        openImage(m_filePath);

        setShowingData(getImage());
    }

    void show() override {
        std::cout << "Show " << getShowingData() << " Viwer" << std::endl;
    }

    void clear() override {
        std::cout << "Clear Image Viwer\n";

        closeImage();
    }

 private:
    std::string m_filePath;
};
