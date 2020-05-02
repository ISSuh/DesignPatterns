/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <gtest/gtest.h>

#include <CreationalPatterns/Builder/builder.hpp>

class Builder_Test : public ::testing::Test {
 public:
    Builder_Test() : m_programmerBuilder(nullptr),
                     m_salseManBuilder(nullptr) {

        m_programmerBuilder = std::unique_ptr<Builder>(new ProgrammerBuilder());
        m_salseManBuilder = std::unique_ptr<Builder>(new SalesManBuilder());;
    }

    ~Builder_Test() = default;

    PeopleDirector m_director;
    std::unique_ptr<Builder> m_programmerBuilder;
    std::unique_ptr<Builder> m_salseManBuilder;
};

TEST_F(Builder_Test, TestConstructProgrammer) {
    m_director.setBuilder(std::move(m_programmerBuilder));
    auto programmer = m_director.constructPeople("Suh", 30);

    ASSERT_EQ("Suh", programmer->getName());
    ASSERT_EQ(30, programmer->getAge());
    ASSERT_EQ("Programmer", programmer->getJob());
}

TEST_F(Builder_Test, TestConstructSalesMan) {
    m_director.setBuilder(std::move(m_salseManBuilder));
    auto salesMan = m_director.constructPeople("John", 42);

    ASSERT_EQ("John", salesMan->getName());
    ASSERT_EQ(42, salesMan->getAge());
    ASSERT_EQ("SalesMan", salesMan->getJob());
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
