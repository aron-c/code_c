#include <iostream>
using namespace std;

int *func()
{
    int *p = new int(10);
    return p;
}
int *func2()
{
    int a = 15;
    cout << a << endl;
    return &a;
}

int main()
{
    cout << "hello world!" << endl;

    int *p = func();
    cout << *p << endl;

    int *p2 = func2();
    *p2 =20;
    cout << p2 << endl;
    cout << *p2 << endl;
    cout << "第二次打p2:" << endl;
    cout << *p2 << endl;

    cout << "删除p堆前" << endl;
    cout << *p << endl;
    delete p;
    cout << "删除p堆后" << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;




int b =30;
int *p3 =&b;
cout<<p3<<endl;
cout<<*p3<<endl;
    return 0;
}
