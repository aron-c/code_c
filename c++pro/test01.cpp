#include <iostream>
using namespace std;
//实现通用数组排序

template <class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] > arr[j])
            {
                max = j; /* code */
            }
        }

        if (max != i)
        {
            mySwap(arr[max], arr[i]); /* code */
        }
    }
}

template <class T>
void myPrint(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    char charArr[] = "afgbicdhe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    myPrint(charArr, num);
}

void test02()
{
    int intArr[] = {9, 3, 5, 1, 3, 6, 7, 8, 2, 4};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    myPrint(intArr, num);
}

int main()
{
    test01();
    test02();
    return 0;
}