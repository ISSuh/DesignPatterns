/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <gtest/gtest.h>

#include <CreationalPatterns/Abstract_Factory/abstract_factory.hpp>

class Factory_Test : public ::testing::Test {
 public:
    Factory_Test() : m_factory1(nullptr),
                       m_factory2(nullptr),
                       m_a1(nullptr),
                       m_b1(nullptr),
                       m_a2(nullptr),
                       m_b2(nullptr) {

        m_factory1 = new Factory_1();
        m_factory2 = new Factory_2();
    }

    ~Factory_Test() {
        delete m_factory1;
        delete m_a1;
        delete m_b1;
        
        delete m_factory2;
        delete m_a2;
        delete m_b2;
    }

    Factory_1* m_factory1;
    Factory_2* m_factory2;

    AbstractProductA* m_a1;
    AbstractProductB* m_b1;
    AbstractProductA* m_a2;
    AbstractProductB* m_b2;
};

TEST_F(Factory_Test, TestCretaeProductA1) {
    m_a1 = m_factory1->cretaeProductA();
    ASSERT_TRUE(m_a1 != nullptr);
}

TEST_F(Factory_Test, TestCretaeProductB1) {
    m_b1 = m_factory1->cretaeProductB();
    ASSERT_TRUE(m_b1 != nullptr);
}

TEST_F(Factory_Test, TestCretaeProductA2) {
    m_a2 = m_factory2->cretaeProductA();
    ASSERT_TRUE(m_a2 != nullptr);
}

TEST_F(Factory_Test, TestCretaeProductB2) {
    m_b2 = m_factory2->cretaeProductB();
    ASSERT_TRUE(m_b2 != nullptr);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
