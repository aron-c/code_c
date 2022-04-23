#include <iostream>
using namespace std;

//计算器案例

class Calculator
{
private:
    /* data */
public:
    Calculator(/* args */);
    ~Calculator();

    int getRes(string oper)
    {
        if (oper == "+")
        {
            return m_num1 + m_num2;
        }
        else if (oper == "-")
        {
            return m_num1 - m_num2;
        }
        else if (oper == "*")
        {
            return m_num1 * m_num2;
        }
        else if (oper == "/")
        {
            return m_num1 / m_num2;
        }
    }
    int m_num1;
    int m_num2;
};

Calculator::Calculator(/* args */)
{
}

Calculator::~Calculator()
{
}

class Abcalculator
{
private:
    /* data */
public:
    Abcalculator(/* args */);
    ~Abcalculator();

    // virtual int getRes()
    // {
    //     return 0;
    // }
    int m_num1;
    int m_num2;

    virtual int getRes()=0;
    // 纯虚函数，该类称为抽象类，无法实例化对象
};

Abcalculator::Abcalculator(/* args */)
{
}

Abcalculator::~Abcalculator()
{
}
class Add : public Abcalculator
{
    virtual int getRes()
    {
        return m_num1 + m_num2;
    }
};
class Sub : public Abcalculator
{
    virtual int getRes()
    {
        return m_num1 - m_num2;
    }
};
class Mul : public Abcalculator
{
    virtual int getRes()
    {
        return m_num1 * m_num2;
    }
};
class Chu : public Abcalculator
{
    virtual int getRes()
    {
        return m_num1 / m_num2;
    }
};

void test01()
{
    Calculator c1;
    c1.m_num1 = 10;
    c1.m_num2 = 10;
    std::cout << c1.m_num1 << "+" << c1.m_num2 << "=" << c1.getRes("+") << '\n';
    std::cout << c1.m_num1 << "-" << c1.m_num2 << "=" << c1.getRes("-") << '\n';
    std::cout << c1.m_num1 << "*" << c1.m_num2 << "=" << c1.getRes("*") << '\n';
    std::cout << c1.m_num1 << "/" << c1.m_num2 << "=" << c1.getRes("/") << '\n';
}

void test02()
{
    Abcalculator *c1 = new Add;
    c1->m_num1 = 100;
    c1->m_num2 = 100;
    std::cout << c1->m_num1 << "+" << c1->m_num2 << "=" << c1->getRes() << '\n';
    delete c1;

    c1 = new Sub;
    c1->m_num1 = 100;
    c1->m_num2 = 100;
    std::cout << c1->m_num1 << "-" << c1->m_num2 << "=" << c1->getRes() << '\n';
    delete c1;

    c1 = new Mul;
    c1->m_num1 = 100;
    c1->m_num2 = 100;
    std::cout << c1->m_num1 << "*" << c1->m_num2 << "=" << c1->getRes() << '\n';
    delete c1;

    c1 = new Chu;
    c1->m_num1 = 100;
    c1->m_num2 = 100;
    std::cout << c1->m_num1 << "/" << c1->m_num2 << "=" << c1->getRes() << '\n';
    delete c1;

    // Abcalculator c2; 不能实例化对象
}
int main()
{
    cout << "hello world!" << endl;
    test01();
    test02();
    return 0;
}
