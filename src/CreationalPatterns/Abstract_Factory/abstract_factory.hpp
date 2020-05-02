/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

/**
 * @brief AbstractProduct - AbstractProductA
 * @details
 */
class AbstractProductA {
 public:
    virtual ~AbstractProductA() = default;
    virtual void printA() = 0;
};

/**
 * @brief AbstractProductB - AbstractProductA
 * @details
 */
class AbstractProductB {
 public:
    virtual ~AbstractProductB() = default;
    virtual void printB() = 0;
};

/**
 * @brief ConcreteProduct - ProductA1
 * @details
 */
class ProductA1 : public AbstractProductA {
 public:
    void printA() override { std::cout << "ProductA-1" << std::endl; }
};

/**
 * @brief ConcreteProduct - ProductA2
 * @details
 */
class ProductA2 : public AbstractProductA {
 public:
    void printA() override { std::cout << "ProductA-2" << std::endl; }
};

/**
 * @brief ConcreteProduct - ProductB1
 * @details
 */
class ProductB1 : public AbstractProductB {
 public:
    void printB() override { std::cout << "ProductB-1" << std::endl; }
};

/**
 * @brief ConcreteProduct - ProductB2
 * @details
 */
class ProductB2 : public AbstractProductB {
 public:
    void printB() override { std::cout << "ProductB-2" << std::endl; }
};

/**
 * @brief AbstractFactory - AbstractFactory
 * @details
 */
class AbstractFactory {
 public:
    virtual ~AbstractFactory() = default;

    virtual AbstractProductA* cretaeProductA() = 0;
    virtual AbstractProductB* cretaeProductB() = 0;
};

/**
 * @brief ConcreteFactory - Factory_1
 * @details
 */
class Factory_1 : public AbstractFactory {
 public:
    AbstractProductA* cretaeProductA() override {
        return dynamic_cast<AbstractProductA*>(new ProductA1());
    }

    AbstractProductB* cretaeProductB() override {
        return dynamic_cast<AbstractProductB*>(new ProductB1());
    }
};

/**
 * @brief ConcreteFactory - Factory_2
 * @details
 */
class Factory_2 : public AbstractFactory {
 public:
    AbstractProductA* cretaeProductA() {
        return dynamic_cast<AbstractProductA*>(new ProductA2());
    }

    AbstractProductB* cretaeProductB() {
        return dynamic_cast<AbstractProductB*>(new ProductB2());
    }
};
