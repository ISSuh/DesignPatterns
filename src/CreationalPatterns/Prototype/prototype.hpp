/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

typedef struct {
    int x = 0;
    int y = 0;
} Position;

enum class GRAPHIC_TYPE : uint8_t {
    CIRCLE,
    TRIANGLE
};

/**
 * @brief Prototype - Graphic
 * @details
 */
class Graphic {
 public:
    virtual ~Graphic() = default;

    virtual void draw() = 0;

    // Prototype Pattern에서의 복사 및 초기화 연산
    virtual Graphic* clone() const = 0;
    virtual void initialize(const Position& pos) = 0;

    void setPosition(const Position& pos) {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }

    const Position& getPosition() const {
        return m_pos;
    }

 private:
    Position m_pos;
};

/**
 * @brief ConcretePrototype - Circle
 * @details
 */
class Circle : public Graphic {
 public:
    Circle() = default;
    Circle(const Circle& rhs) {
        setPosition(rhs.getPosition());
    }

    Graphic* clone() const override {
        return dynamic_cast<Graphic*>(new Circle(*this));
    }

    void initialize(const Position& pos) override {
        setPosition(pos);
    }

    void draw() override {
        std::cout << "Viewing Circle at ( "
                    << getPosition().x << ','
                    << getPosition().y << " )\n";
    };
};

/**
 * @brief ConcretePrototype - Triangle
 * @details
 */
class Triangle : public Graphic {
 public:
    Triangle() = default;
    Triangle(const Triangle& rhs) {
        setPosition(rhs.getPosition());
    }

    Graphic* clone() const override {
        return dynamic_cast<Graphic*>(new Triangle(*this));
    }

    void initialize(const Position& pos) override {
        setPosition(pos);
    }

    void draw() override {
        std::cout << "Viewing Triangle at ( "
                    << getPosition().x << ','
                    << getPosition().y << " )\n";
    };
};

/**
 * @brief Client - Triangle
 * @details
 */
class GrapicFactory {
 public:
    GrapicFactory() : m_graphic(nullptr) { }

    void setGraphicType(GRAPHIC_TYPE type) {
        switch (type) {
        case GRAPHIC_TYPE::CIRCLE : {
            if (m_graphic != nullptr) {
                m_graphic.reset();
            }

            m_graphic = std::unique_ptr<Graphic>(new Circle());

            break;
        }
        case GRAPHIC_TYPE::TRIANGLE : {
            if (m_graphic != nullptr) {
                m_graphic.reset();
            }

            m_graphic = std::unique_ptr<Graphic>(new Triangle());

            break;
        }
        default :
            m_graphic = nullptr;
            break;
        }
    }

    Graphic* createGraphic(const Position& pos) const {
        Graphic* graphic = m_graphic->clone();
        graphic->initialize(pos);

        return graphic;
    }

 private:
    std::unique_ptr<Graphic> m_graphic;
};
