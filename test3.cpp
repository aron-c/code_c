#include <iostream>
#define day 7
using namespace std;
// 过7
int main()
{
    for (int i = 0; i < +100; i++)
    {
        if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
        {
            cout << "敲桌子" << endl; /* code */
        }

        else
        {
            cout << i << endl; /* code */
        }

        /* code */
    }

    return 0;
}
