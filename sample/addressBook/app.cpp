#include <iostream>
#include <unistd.h>
#include <string>
#include "app.h"
using namespace std;
#define maxSize 1000;

void addressMember(struct addressBook *abs)
{
    if (abs->mSize == maxSize)
    {
        cout << "通讯录已满，无法添加" << endl;
        return 0;
        /* code */
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->mArr[abs->mSize].mName = name;
    }
}