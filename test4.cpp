#include <iostream>
#define day 7
using namespace std;
// 乘法口诀表
int main()
{
    int count = 10;
    for (int i = 1; i < count; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << "*" << j << "=" << i * j<<" "; /* code */
        }
        cout << endl;
        /* code */
    }

    return 0;
}
