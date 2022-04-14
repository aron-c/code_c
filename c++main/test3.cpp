#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14;

class Student
{
public:
    string mName;
    int mId;

    void showStud()
    {
        cout << "学生姓名：" << mName << endl;
        cout << "学生学号：" << mId << endl;
    }

    void setName(string name)
    {
        mName = name;
    }
};

class Person
{
public:
private:
    string mName int mPwd;

};

int
main()
{
    cout << "hello world!" << endl;

    Student s1;
    s1.mName = "zhangsan";
    s1.mId = 193131389;
    s1.showStud();

    Student s2;
    s2.setName("lisi");
    s2.mId = 123123123;
    s2.showStud();

    PersonOne p1;
    p1.func2();

    return 0;
}
