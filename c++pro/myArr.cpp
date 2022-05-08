#include <iostream>
using namespace std;
#include "myArr.hpp"

void myPrint(myArr<int> &arr)
{
    cout << "数组中的数据为：" << endl;
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{

    myArr<int> arr1(6);
    myArr<int> arr2(10);
    arr2 = arr1;
}

void test02()
{
    myArr<int> arr3(5);
    for (int i = 0; i < 5; i++)
    {
        arr3.pushBack(i);
    }

    myArr<int> arr4(6);
    for (int i = 0; i < 6; i++)
    {
        arr4[i] = i;
    }

    myPrint(arr3);
    myPrint(arr4);
}

int main()
{
    // test01();
    test02();
    return 0;
}