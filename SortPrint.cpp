#include<iostream>
#include "SortPrint.h"
using namespace std;

void Sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                /* code */
            }
            /* code */
        }
    }
}
void Print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl; /* code */
    }
}