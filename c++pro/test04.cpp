#include <iostream>
using namespace std;
#include <string>
#include <typeinfo>

template <class T1, class T2>
class Person
{
private:
    /* data */
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

    T1 m_name;
    T2 m_age;
};

//指定传入类型----更常用-----
void myPrint(Person<string, int> &p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p1("悟空", 10000);
    myPrint(p1);
}

//参数模板化
template <class T1, class T2>
void myPrint2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1的数据类型" << typeid(T1).name() << endl;
    cout << "T2的数据类型" << typeid(T2).name() << endl;
}
void test02()
{
    Person<string, int> p2("猪八戒", 8000);
    myPrint(p2);
}

//整个类全部模板化
template <class T>
void myPrint3(T &p)
{
    p.showPerson();
    cout << "T1的数据类型" << typeid(T).name() << endl;
}
void test03()
{
    Person<string, int> p3("沙僧", 6000);
    myPrint(p3);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}