/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <memory>

/**
 * @brief Product - People
 * @details
 */
class People {
 public:
    void setName(const std::string& name) { m_name = name; }
    void setAge(const int age) { m_age = age; }
    void setJob(const std::string& job) { m_job = job; }

    void printInfo() const {
        std::cout << "Name : " << m_name << std::endl;
        std::cout << "Age : " << m_age << std::endl;
        std::cout << "Job : " << m_job << std::endl;
    }

 private:
    std::string m_name;
    int m_age;
    std::string m_job;
};

/**
 * @brief Builder - Builder
 * @details
 */
class Builder {
 public:
    virtual ~Builder() = default;

    void createPeople() { m_people = std::make_shared<People>(); }
    std::shared_ptr<People> getPeople() const { return m_people; }

    virtual void buildName(const std::string& name) = 0;
    virtual void buildAge(const int age) = 0;
    virtual void buildJob() = 0;

 private:
    std::shared_ptr<People> m_people = nullptr;
};

/**
 * @brief ConcreteBuilder - Programmer
 * @details
 */
class ProgrammerBuilder : public Builder {
 public:
    void buildName(const std::string& name) override {
        getPeople()->setName(name);
    }

    void buildAge(const int age) override {
        getPeople()->setAge(age);
    }

    void buildJob() override {
        getPeople()->setJob("Programmer");
    }
};

/**
 * @brief ConcreteBuilder - SalesManBuilder
 * @details
 */
class SalesManBuilder : public Builder {
 public:
    void buildName(const std::string& name) override {
        getPeople()->setName(name);
    }

    void buildAge(const int age) override {
        getPeople()->setAge(age);
    }

    void buildJob() override {
        getPeople()->setJob("SalesMan");
    }
};

/**
 * @brief Director - PeopleDirector
 * @details
 */
class PeopleDirector {
 public:
    void setBuilder(std::unique_ptr<Builder> builder) {
        if (m_builder != nullptr) {
            m_builder.reset();
        }

        m_builder = std::move(builder);
    }

    std::shared_ptr<People> constructPeople(const std::string& name,
                                            const int age) {
        m_builder->createPeople();

        m_builder->buildName(name);
        m_builder->buildAge(age);
        m_builder->buildJob();

        return m_builder->getPeople();
    }

 private:
    std::unique_ptr<Builder> m_builder = nullptr;
};

int main() {
    PeopleDirector director;
    auto programmerBuilder = std::unique_ptr<Builder>(new ProgrammerBuilder());
    auto salesManBuilder = std::unique_ptr<Builder>(new SalesManBuilder());
    
    director.setBuilder(std::move(programmerBuilder));
    auto programmer = director.constructPeople("Suh", 30);
    programmer->printInfo();

    std::cout << std::endl;

    director.setBuilder(std::move(salesManBuilder));
    auto salesMan = director.constructPeople("John", 42);
    salesMan->printInfo();
}
