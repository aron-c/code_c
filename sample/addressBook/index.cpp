#include <iostream>
#include <unistd.h>
#include <string>
#include <term.h>
// #include "app.h"
// #include "app.cpp"
using namespace std;
#define maxSize 1000

struct member
{
    string mName;
    int mSex;
    int mAge;
    string mPhone;
    /* data */
};

struct addressBook
{
    struct member mArr[maxSize];
    int mSize;
    /* data */
};

void addressMember(struct addressBook *abs)
{
    if (abs->mSize == maxSize)
    {
        cout << "通讯录已满，无法添加" << endl;
        // return 0;
        /* code */
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->mArr[abs->mSize].mName = name;

        int sex;
        cout << "请输入性别：" << endl;
        cout << "1————男" << endl;
        cout << "2————女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->mArr[abs->mSize].mSex = sex; /* code */
                break;
            }
            else
            {
                cout << "请重新输入：" << endl;
            } /* code */
        }

        int age;
        cout << "请输入年龄：" << endl;
        while (true)
        {
            cin >> age;
            if (age >= 1 && age <= 100)
            {
                abs->mArr[abs->mSize].mAge = sex; /* code */
                break;
            }
            else
            {
                cout << "请重新输入：" << endl;
            } /* code */
        }

        string phone;
        cout << "请输入电话：" << endl;
        cin >> phone;
        abs->mArr[abs->mSize].mPhone = phone;
        // cout << "添加成功！" << endl;
        abs->mSize++;
    }
}

int showMenu()
{
    cout << "——————————————————————————" << endl;
    cout << "|***** 1.添加联系人*****| " << endl;
    cout << "|***** 2.显示联系人*****| " << endl;
    cout << "|***** 3.删除联系人*****| " << endl;
    cout << "|***** 4.查找联系人*****| " << endl;
    cout << "|***** 5.修改联系人*****| " << endl;
    cout << "|***** 6.清空联系人*****| " << endl;
    cout << "|***** 0.退出通讯录*****| " << endl;
    cout << "——————————————————————————" << endl;
}

int main()
{

    int select = 0;
    // cout << "hello world!" << endl;
    addressBook abs;
    abs.mSize = 0;
    while (true)
    {
        showMenu();

        cin >> select;
        switch (select)
        {
        case 1:
            addressMember(&abs);
            printf("\x1b[H\x1b[2J"); 
            cout << "添加成功！" << endl;
            // system("clear");
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 0:
            cout << "欢迎下次使用！" << endl;
            return 0;
            break;

        default:
            cout << "重新选择" << endl;
            break;
        } /* code */
    }

    pause();
    return 0;
}
