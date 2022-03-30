#include <iostream>
#define day 7
using namespace std;
// 比较大小
int main()
{
    int a, b, c = 0;
    std::cout << "请输入a,b,c三只猪的体重" << '\n';
    cin >> a;
    cin >> b;
    cin >> c;
    cout << "三只猪的重量分别为" << a << "," << b << "," << c << endl;

    if (a >= b)
    {
        if (a >= c)
        {
            cout << "最重的是a,重量是" << a << endl;
            /* code */
        }
        else
        {
            cout << "最重的是c,重量是" << c << endl;
        }
    }
    else
    {
        if (b >= c)
        {
            cout << "最重的是b,重量是" << b << endl;
            /* code */
        }
        else
        {
            cout << "最重的是c,重量是" << c << endl;
        }
    }
    return 0;
}