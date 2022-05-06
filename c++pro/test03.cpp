#include <iostream>
using namespace std;
#include <string>

template <class NameType, class AgeType = int>
class Person
{
private:
    /* data */
public:
    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    };

    NameType m_name;
    AgeType m_age;

    void showPerson()
    {
        cout << this->m_name << ",年龄：" << this->m_age << endl;
    }
};

// template <class T>

void test01()
{
    Person<string, int> p1("悟空", 10000);

    p1.showPerson();
}

void test02()
{
    Person<string> p2("猪八戒", 8000);
    p2.showPerson();
}

int main()
{
    test01();
    test02();
    return 0;
}