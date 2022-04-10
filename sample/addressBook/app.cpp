#include <iostream>
#include <unistd.h>
#include <string>
#include <term.h>
#include "app.h"
// #include "app.cpp"
using namespace std;
#define maxSize 1000

struct member
{
    // 联系人结构体
    string mName;
    int mSex;
    int mAge;
    string mPhone;
    /* data */
};

struct addressBook
{
    // 通讯录结构体
    struct member mArr[maxSize];
    int mSize;
    /* data */
};

void addressMember(struct addressBook *abs)
{
    // 添加联系人
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
                abs->mArr[abs->mSize].mAge = age; /* code */
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
    cout << "添加成功！" << endl;
}

void showMember(struct addressBook *abs)
{
    // 显示所有后联系人
    if (abs->mSize == 0)
    {
        cout << "当前通讯录中没有联系人！请添加联系人" << endl; /* code */
    }
    else
    {

        for (int i = 0; i < abs->mSize; i++)
        {
            cout << "姓名：" << abs->mArr[i].mName << "\t";
            cout << "性别：" << (abs->mArr[i].mSex == 1 ? "男" : "女") << "\t";
            // if (abs->mArr[i].mSex == 1)
            // {
            //     cout << "性别："
            //          << "男" << endl; /* code */
            // }
            // else
            // {
            //     cout << "性别："
            //          << "nv" << "\t";
            // }
            cout << "年龄：" << abs->mArr[i].mAge << "\t";
            cout << "电话：" << abs->mArr[i].mPhone << endl; /* code */
        }
    }
}

int is_Here(struct addressBook *abs, string name)
{
    // 查询，修改，删除都需要查找联系人
    for (int i = 0; i < abs->mSize; i++)
    {
        if (abs->mArr[i].mName == name)
        {
            return i; /* code */
        }             /* code */
    }
    return -1;
}

void deMember(struct addressBook *abs)
{
    // 删除联系人

    cout << "请输入要删除的姓名：" << endl;
    string name;
    cin >> name;
    int tag;
    // tag = is_Here(&abs, name);
    tag = is_Here(abs, name);
    if (tag == -1)
    {
        cout << "查无此人!" << endl; /* code */
    }
    else
    {
        cout << "找到此人！" << endl;
        cout << "原编号为：" << tag << endl;
        for (int i = tag; i < abs->mSize; i++)
        {
            abs->mArr[i] = abs->mArr[i + 1];
            /* code */
        }
        abs->mSize--;
        cout << "删除成功！" << endl;
    }
}

void findMember(struct addressBook *abs)
{
    // 查找联系人
    cout << "请输入要查找的姓名：" << endl;
    string name;
    cin >> name;
    int tag;
    // tag = is_Here(&abs, name);
    tag = is_Here(abs, name);
    if (tag == -1)
    {
        cout << "查无此人!" << endl; /* code */
    }
    else
    {
        cout << "找到此人！" << endl;
        cout << "原编号为：" << tag << endl;
        cout << "姓名：" << abs->mArr[tag].mName << "\t";
        cout << "性别：" << (abs->mArr[tag].mSex == 1 ? "男" : "女") << "\t";
        // if (abs->mArr[i].mSex == 1)
        // {
        //     cout << "性别："
        //          << "男" << endl; /* code */
        // }
        // else
        // {
        //     cout << "性别："
        //          << "nv" << "\t";
        // }
        cout << "年龄：" << abs->mArr[tag].mAge << "\t";
        cout << "电话：" << abs->mArr[tag].mPhone << endl; /* code */
    }
}

void modMember(struct addressBook *abs)
{
    // 修改联系人
    cout << "请输入要修改的姓名：" << endl;
    string name;
    cin >> name;
    int tag;
    // tag = is_Here(&abs, name);
    tag = is_Here(abs, name);
    if (tag == -1)
    {
        cout << "查无此人!" << endl; /* code */
    }
    else
    {
        cout << "找到此人！" << endl;
        cout << "原编号为：" << tag << endl;

        cout << "姓名：" << abs->mArr[tag].mName << "\t";
        cout << "输入修改后的姓名：" << endl;
        string name;
        cin >> name;
        abs->mArr[tag].mName = name;

        cout << "性别：" << (abs->mArr[tag].mSex == 1 ? "男" : "女") << "\t";
        cout << "输入修改后的性别：" << endl;
        cout << "1————男" << endl;
        cout << "2————女" << endl;
        int sex;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->mArr[tag].mSex = sex; /* code */
                break;
            }
            else
            {
                cout << "请重新输入：" << endl;
            } /* code */
        }

        cout << "年龄：" << abs->mArr[tag].mAge << "\t";
        cout << "输入修改后的年龄：" << endl;
        int age;
        while (true)
        {
            cin >> age;
            if (age >= 1 && age <= 100)
            {
                abs->mArr[tag].mAge = age; /* code */
                break;
            }
            else
            {
                cout << "请重新输入：" << endl;
            } /* code */
        }

        cout << "电话：" << abs->mArr[tag].mPhone << endl;
        cout << "输入修改后的电话：" << endl; /* code */
        string phone;
        cin >> phone;
        abs->mArr[tag].mPhone = phone;

        cout << "修改成功！" << endl;
    }
}

void clsMember(struct addressBook *abs)
{
    // 清除联系人
    cout << "清空成功！" << endl;
    abs->mSize = 0;
    cout << "清空成功！" << endl;
}

int showMenu()
{
    //显示目录
    cout << "——————————————————————————" << endl;
    cout << "|***** 1.添加联系人*****| " << endl;
    cout << "|***** 2.显示联系人*****| " << endl;
    cout << "|***** 3.删除联系人*****| " << endl;
    cout << "|***** 4.查找联系人*****| " << endl;
    cout << "|***** 5.修改联系人*****| " << endl;
    cout << "|***** 6.清空联系人*****| " << endl;
    cout << "|***** 0.退出通讯录*****| " << endl;
    cout << "——————————————————————————" << endl;
    cout << "请选择功能" << endl;
}

void backMenu()
{
    
    //实现返回菜单
    cout << "按任意键返回菜单" << endl;
    cin.get();
    cin.get();
    printf("\x1b[H\x1b[2J");
}