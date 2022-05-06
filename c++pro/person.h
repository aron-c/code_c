#pragma once
#include <iostream>
using namespace std;


template <class T1, class T2>
class Person
{
private:
    /* data */
public:
    Person(T1 name, T2 age);
    ~Person();

    void showInfo();
    // {
    //     cout << this->m_name << ",年龄：" << this->m_age << endl;
    // }

    T1 m_name;
    T2 m_age;
};