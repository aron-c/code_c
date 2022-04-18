#include <iostream>
using namespace std;

class Person
{

public:
    Person(int age)
    {
        this->age = age;
    }

    Person &addPersonAge(Person &p)
    {
        this->age += p.age;
        return *this;
    }
    int age;
};

void test01()
{
    Person p1(18);
    Person p2(10);
    p2.addPersonAge(p1).addPersonAge(p1).addPersonAge(p1);
    cout << "p1年龄：" << p1.age << endl;
    cout << "p2年龄：" << p2.age << endl;
}
int main()
{
    cout << "hello world!" << endl;
    test01();

    return 0;
}
