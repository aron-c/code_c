#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "person.cpp"

template <class T>
class Base
{
    T m;
};
class Son : public Base<int>
{
};

template <class T1, class T2>
class Son2 : public Base<T2>
{
    T1 obj;
};

void test01()
{
    Son s1;
}
void test02()
{
    Son2<string, int> s2;
}

// template <class T1, class T2>
// class Person
// {
// private:
//     /* data */
// public:
//     Person(T1 name, T2 age);
//     ~Person();

//     void showInfo();
//     // {
//     //     cout << this->m_name << ",年龄：" << this->m_age << endl;
//     // }

//     T1 m_name;
//     T2 m_age;
// };

// template <class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age)
// {
//     this->m_name = name;
//     this->m_age = age;
// }
// template <class T1, class T2>
// Person<T1, T2>::~Person()
// {
// }
// template <class T1, class T2>
// void Person<T1, T2>::showInfo()
// {
//     cout << this->m_name << ",年龄：" << this->m_age << endl;
// }

void test03()
{
    Person<string, int> p1("悟空", 10000);
    p1.showInfo();
}
int main()
{
    test03();
    return 0;
}