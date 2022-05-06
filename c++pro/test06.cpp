#include <iostream>
using namespace std;

template <class T1, class T2>
class Person;

template <class T1, class T2>
void showInfo2(Person<T1, T2> &p)
{
    cout << "全局函数2调用" << p.m_name << ",年龄：" << p.m_age << endl;
}

template <class T1, class T2>
class Person
{

    friend void showInfo(Person<T1, T2> &p)
    {
        cout << "全局函数1调用" << p.m_name << ",年龄：" << p.m_age << endl;
    }

    friend void showInfo2<>(Person<T1, T2> &p);

private:
    T1 m_name;
    T2 m_age;

public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void showPerson()
    {
        cout << this->m_name << ",年龄：" << this->m_age << endl;
    }
};

//全局函数类内实现
void test01()
{
    Person<string, int> p1("tom", 10);
    showInfo(p1);
}

//全局函数类外实现
void test02()
{
    Person<string, int> p2("jerry", 15);
    showInfo2(p2);
}

int main()
{
    test01();
    test02();
    return 0;
}