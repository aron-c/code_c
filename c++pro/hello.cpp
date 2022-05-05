#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << "hello world!" << endl;
    int a = 10;
    int b = 20;
    swap(a, b);

    cout << "a=" << a << endl;
    std::cout << "b=" << b << '\n';

    double c = 12.3;
    double d = 45.6;
    swap(c, d);
    cout << "c=" << c << endl;
    std::cout << "d=" << d << '\n';

    mySwap(a, b);
    mySwap(c, d);
    cout << "a=" << a << endl;
    std::cout << "b=" << b << '\n';
    cout << "c=" << c << endl;
    std::cout << "d=" << d << '\n';

    return 0;
}
