#include <iostream>
using namespace std;
#include <string>

class Person
{
private:
    /* data */
public:
    Person(string name, int age);
    ~Person();

    string m_name;
    int m_age;
};

Person::Person(string name, int age)
{
    this->m_name = name;
    this->m_age = age;
}

Person::~Person()
{
}

template <class T>
bool myCom(T a, T b)
{
    if (a == b)
    {
        return true; /* code */
    }
    else
    {
        return false;
    }
}
template <>
bool myCom(Person a, Person b)
{
    if (a.m_name == b.m_name && a.m_age == b.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
void test01()
{
    int a = 10;
    int b = 20;

    bool ret = myCom(a, b);
    if (ret)
    {
        cout << "a与b相等" << endl;
    }
    else
    {
        cout << "a与b不相等" << endl;
    }
}

void test02()
{
    Person p1("tom", 10);
    Person p2("tom", 10);

    bool ret = myCom(p1, p2);
    if (ret)
    {
        cout << "p1与p2相等" << endl;
    }
    else
    {
        cout << "p1与p2不相等" << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}