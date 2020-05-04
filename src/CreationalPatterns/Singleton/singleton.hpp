/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>

class MyClass {
public:
    static MyClass& getInstence() {
        static MyClass singleton;

        return singleton;
    }

    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }

    MyClass(const MyClass& rhs) = delete;
    MyClass operator=(const MyClass& rhs) = delete;

protected:
    MyClass() : m_name("MyClass") {}

private:
    std::string m_name;
};
