#include <iostream>
#include "SortPrint.h"
using namespace std;
#include "SortPrint.cpp"

// 指针冒泡排序

int main()
{
    int arr[] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5, 50};
    int len = sizeof(arr) / sizeof(arr[0]);
    Sort(arr, len);
    Print(arr, len);
    return 0;
}