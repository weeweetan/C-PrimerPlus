//
// Created by 11135 on 2020/8/20.
//

#include <string>
#include <iostream>

using std::cout;
using std::endl;

template <class NameType, class AgeType>
class Person
{
private:
    NameType m_Name;
    AgeType m_Age;

public:
    Person(NameType name, AgeType age)
    {
        m_Name = name;
        m_Age = age;
    }

    void showInfo()
    {
        cout << "name: " << m_Name << " age: " << m_Age << endl;
    }


};


int main(int argc, char **argv)
{
    Person<std::string ,int> p1("孙悟空", 999);
    p1.showInfo();
}