#include <iostream>
using namespace std;

//制作饮品案例

class AbDrink
{
private:
    /* data */
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void InCup() = 0;
    virtual void PutSt() = 0;
    void makeDrink()
    {
        Boil();
        Brew();
        InCup();
        PutSt();
    }
};


class Coffee : public AbDrink
{
private:
    /* data */
public:
    virtual void Boil()
    {
        cout << "煮水" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    virtual void InCup()
    {
        cout << "倒杯里" << endl;
    }
    virtual void PutSt()
    {
        cout << "放糖" << endl;
    }
};



class Tea : public AbDrink
{
private:
    /* data */
public:
    virtual void Boil()
    {
        cout << "煮水" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }
    virtual void InCup()
    {
        cout << "倒杯里" << endl;
    }
    virtual void PutSt()
    {
        cout << "放枸杞" << endl;
    }
};

void doWork(AbDrink *abs)
{
    abs->makeDrink();
    delete abs;
}
void test01()
{
    doWork(new Coffee);
    std::cout << "-----------------------------" << '\n';
    doWork(new Tea);
}

int main()
{
    test01();
    cout << "hello world!" << endl;

    return 0;
}
