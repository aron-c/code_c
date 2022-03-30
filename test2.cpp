#include <iostream>
#define day 7
using namespace std;
// 猜数字
int main()
{
    // 1。生成随机数
    // 2.玩家猜数
    //  3.判断正误
    srand((unsigned int)time(NULL));
    int num = rand() % 100 + 1;
    // cout << num << endl;

    cout << "已生成数字，请输入猜测数字" << endl;
    int val = 0;
    int min = 1;
    int max = 100;
    while (1)
    {
        cin >> val;
        if (val > num)
        {
            max = val;
            cout << "数字在" << min << "-" << max << "之间" << endl;
            cout << "猜测过大,请重新输入" << endl; /* code */
        }
        else if (val < num)
        {
            min = val;
            cout << "数字在" << min << "-" << max << "之间" << endl;
            cout << "猜测过小,请重新输入" << endl;
        }
        else
        {

            cout << "猜测正确,数字为：" << num << endl;
            break;
        }
        /* code */
    }

    return 0;
}
