#include <iostream>
#include <string>
using namespace std;

class Person 
{
private:
    string mName;
    int mAge;
    string mLove;

    /* data */
public:
    void setName(string name)
    {
        mName = name;
    }
    string getName()
    {

        return mName;
    };

    void setAge(int age)
    {
        if (age < 0 || age > 100)
        {

            mAge = 18;
            cout << "输入错误了" << endl;
            return;
            /* code */
        }

        mAge = age;
    };

    int getAge()
    {
        return mAge;
    };

    int setLove(string love)
    {
        mLove = love;
    };
};

int main()
{
    cout << "hello world!" << endl;

    Person p;
    p.setName("zhansan");
    cout << "hello world!" << p.getName() << endl;
    cout << "hello world!" << p.getAge() << endl;

    int age;
    cin >> age;
    p.setAge(age);
    cout << "hello world!" << p.getAge() << endl;

    return 0;
}
