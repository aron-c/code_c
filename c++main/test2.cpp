#include <iostream>
using namespace std;

// 值传递

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 地址传递
void swap2(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递
void swap3(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << "hello world!" << endl;
    int a = 10;
    int b = 20;
    swap(a, b); //值传递，形参未改变实参
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    swap2(&a, &b); //地址传递
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    int c = 30;
    int d = 40;

    swap3(c, d); //引用传递，可修饰实参
    cout << "c=" << c << endl;
    cout << "d=" << d << endl;

    return 0;
}
