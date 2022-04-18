#include <iostream>
using namespace std;

class cube
{
public:
    void setL(int l = 1)
    {
        mL = l;
    }
    void setW(int w = 1)
    {
        mW = w;
    }
    void setH(int h = 1)
    {
        mH = h;
    }
    int getL()
    {
        return mL;
    }
    int getW()
    {
        return mW;
    }
    int getH()
    {
        return mH;
    }
    int getCubeS()
    {
        return 2 * (mL * mH + mL * mW + mW * mH);
    }
    int getCubeV()
    {
        return mL * mW * mH;
    }
    bool isSameByClass(cube &c)
    {
        if (2 * (mL * mH + mL * mW + mW * mH) == c.getCubeS())
        {
            return true; /* code */
        }
        return false;
    }

private:
    int mL;
    int mW;
    int mH;
};

bool isSame(cube &c1, cube &c2)
{

    if (c1.getCubeS() == c2.getCubeS())
    {
        return true;
        /* code */
    }
    return false;
}
int main()
{
    cout << "hello world!" << endl;

    cube c1;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);
    cout << "面积为：" << c1.getCubeS() << endl;
    cout << "体积为：" << c1.getCubeV() << endl;

    cube c2;
    c2.setH(10);
    c2.setL(10);
    c2.setW(10);
    cout << "面积为：" << c2.getCubeS() << endl;
    cout << "体积为：" << c2.getCubeV() << endl;

    bool ret = isSame(c1, c2);
    if (ret)
    {
        cout << "两正方体面积相同" << endl;
        /* code */
    }
    else
    {
        cout << "两正方体面积不相同" << endl;
    }

    bool ret2 = c1.isSameByClass(c2);
    if (ret2)
    {
        cout << "成员函数判断两正方体面积相同" << endl;
        /* code */
    }
    else
    {
        cout << "成员函数判断两正方体面积不相同" << endl;
    }

    return 0;
}