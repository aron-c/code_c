#include <iostream>
using namespace std;
class Base
{
private:
    int m_B;
    /* data */
public:
    int m_A;
    Base(/* args */);
    ~Base();
    int m_name;
    void func()
    {
        cout << "base func！" << endl;
    }
    static int m_age;

protected:
    int m_C;
};
int Base::m_age = 100;

Base::Base(/* args */)
{
    cout << "base的构造函数" << endl;
    m_name = 100;
}

Base::~Base()
{
    cout << "base的析构函数" << endl;
}

class Son : public Base
{
private:
    /* data */
public:
    Son(/* args */);
    ~Son();
    int m_D;
    int m_name;
    void func()
    {
        cout << "son func！" << endl;
    }
    static int m_age;
};
int Son::m_age = 200;
Son::Son(/* args */)
{
    cout << "son的构造函数" << endl;
    m_name = 200;
}

Son::~Son()
{
    cout << "son的析构函数" << endl;
}

void test01()
{
    Son son;
    cout << "size of son:" << sizeof(Son) << endl;
    cout << "son.m_name" << son.m_name << endl;
    cout << "son.base.m_name" << son.Base::m_name << endl;
}

void test02()
{
    Son son;
    son.func();
    son.Base::func();
}

void test03()
{
    Son son;
    cout << "通过对象访问静态成员属性：" << endl;
    cout << "son.m_age:" << son.m_age << endl;
    cout << "son.base.m_age:" << son.Base::m_age << endl;

    cout << "通过类名访问静态成员属性：" << endl;
    cout << "son.m_age:" << Son::m_age << endl;
    cout << "base.m_age:" << Base::m_age << endl;
    cout << "son.base.m_age:" << Son::Base::m_age << endl;
}

class Animal
{
public:
    int m_Age;
};

class Tuo : virtual public Animal
{
};
class Sheep : virtual public Animal
{
};

class SheepTuo : public Tuo, public Sheep
{
};

void test04()
{
    SheepTuo st;
    st.Sheep::m_Age=18;
    st.Tuo::m_Age=25;
    
}

main()
{
    cout << "hello world!" << endl;
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}
