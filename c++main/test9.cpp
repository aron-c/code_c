#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    int m_A;
    int m_B;
    ~Person();
};

Person::Person(/* args*/)
{
}

Person::~Person()
{
}

Person operator+(Person &p)
{
}

void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 20;
    p2.m_B = 20;

    Person p3 = p1 + p2;
    cout << "p3A=" << p3.m_A << endl;
    cout << "p3B=" << p3.m_B << endl;
}

ostream &operator<<(ostream &cout, Person p)
{
    cout << "pA=" << p.m_A << endl;
    cout << "pB=" << p.m_B << endl;
    return cout;
}
void test02()
{
    Person p;
    p.m_A = 10;
    p.m_B = 20;
    cout << p << endl;
}

class MyInt
{
    friend ostream &operator<<(ostream &cout, MyInt p);

private:
    int m_A;
    /* data */
public:
    MyInt(/* args */);
    MyInt &operator++()
    {
        m_A++;
        return *this;
    }
    MyInt operator++(int)
    {
        MyInt temp;
        temp = *this;
        m_A++;
        return temp;
    }
    ~MyInt();
};

MyInt::MyInt(/* args */)
{
    m_A = 0;
}
MyInt::~MyInt()
{
}
ostream &operator<<(ostream &out, MyInt p)
{
    out << "pA=" << p.m_A;
    return out;
}

void test03()
{
    MyInt mInt;
    cout << mInt << endl;
    cout << ++mInt << endl;
    cout << mInt++ << endl;
    cout << mInt << endl;
}

class Person2
{
private:
    /* data */
public:
    Person2(int age);
    int *m_age;
    ~Person2();

    Person2 &operator=(Person2 &p)
    {
        // m_age=p.m_age;
        // 浅拷贝

        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
            /* code */
        }
        // 深拷贝
        m_age = new int(*p.m_age);
        return *this;
    }
};

Person2::Person2(int age)
{
    m_age = new int(age);
}

Person2::~Person2()
{
    if (m_age != NULL)
    {
        delete m_age;
        m_age = NULL;
        /* code */
    }
}

void test04()
{
    Person2 p1(18);
    Person2 p2(20);
    Person2 p3(28);

    p2 = p1;

    cout << "p1=" << *p1.m_age << endl;
    cout << "p2=" << *p2.m_age << endl;
    cout << "p3=" << *p3.m_age << endl;

    p3 = p2 = p1;
    cout << "p1=" << *p1.m_age << endl;
    cout << "p2=" << *p2.m_age << endl;
    cout << "p3=" << *p3.m_age << endl;
}

class Person3
{
private:
    /* data */
public:
    Person3(int age, string name /* args */);
    int m_age;
    string m_name;
    ~Person3();

    bool operator==(Person3 p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return true; /* code */
        }
        return false;
    }
    bool operator!=(Person3 p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return true; /* code */
        }
        return false;
    }
};

Person3::Person3(int age, string name /* args */)
{
    m_age = age;
    m_name = name;
}

Person3::~Person3()
{
}

void test05()
{
    Person3 p1(18, "tom");
    Person3 p2(19, "tom");

    if (p1 == p2)
    {
        cout << "p1p2相等的" << endl; /* code */
    }
    else
    {
        cout << "p1p2不相等的" << endl;
    }
}

int main()
{
    cout << "hello world!" << endl;
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}
