#include <iostream>
using namespace std;
#include "myArr.hpp"

class Person
{
public:
    //默认构造一定要写！！！
    // 由于写了一个有参构造，「模板」开辟新空间时 newT会使用你的有参构造，有参构造没有传参无法调用，
    // 但是开辟空间需要一个默认构造
    // 但是程序不会提供无参构造了，因此要自己写一个空的实现！！
    Person(){}; //默认构造一定要写！！！
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

void myPrint(myArr<int> &arr)
{
    cout << "数组中的数据为：" << endl;
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void myPersonPrint(myArr<Person> &arr)
{
    cout << "数组中的数据为：" << endl;
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "姓名：" << arr[i].m_name << endl;
        cout << "年龄：" << arr[i].m_age << endl;
        cout << "----------------------" << endl;
    }
}

void test01()
{

    myArr<int> arr1(6);
    myArr<int> arr2(10);
    arr2 = arr1;
}

void test02()
{
    myArr<int> arr3(5);
    for (int i = 0; i < 5; i++)
    {
        arr3.pushBack(i);
    }

    myArr<int> arr4(6);
    for (int i = 0; i < 6; i++)
    {
        arr4[i] = i;
    }

    std::cout << "arr3的容量为" << arr3.getCap() << '\n';
    std::cout << "arr3的大小为" << arr3.getSize() << '\n';
    myPrint(arr3);

    arr4 = arr3;
    arr4.popBack();
    myPrint(arr4);
    std::cout << "arr4的容量为" << arr4.getCap() << '\n';
    std::cout << "arr4的大小为" << arr4.getSize() << '\n';
}

void test03()
{
    myArr<Person> pArr(3);

    Person p1("悟空", 10000);
    Person p2("八戒", 8000);
    Person p3("沙僧", 6000);

    pArr.pushBack(p1);
    pArr.pushBack(p2);
    pArr.pushBack(p3);

    myPersonPrint(pArr);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}