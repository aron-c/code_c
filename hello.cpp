#include <iostream>
#define day 7
using namespace std;
int main()
{
    // int a = 1;
    // const int yue = 30;
    // // day =10;
    // for (; a < 10; a++)
    // {
    //     cout << a << endl;
    //     cout << "一周有" << day << "天" << endl;
    //     cout << "一月有" << yue << "天" << endl;
    //     /* code */
    // }
    // cout << "请给电影打分" << endl;
    // int a = 0;
    // cin >> a;
    // switch (a)
    // {
    // case 10:
    //     cout << "经典电影" << endl; /* code */
    //     break;
    // case 9:
    //     cout << "一般电影" << endl; /* code */
    //     break;

    // default:
    //     cout << "laji" << endl;
    //     break;
    // }

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;

    cout << sizeof(arr) / sizeof(arr[0]) << endl;
    // cout << (int) arr << endl;
    cout << (int)&arr[5] << endl;
    return 0;
}
