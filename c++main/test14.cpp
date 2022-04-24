#include <iostream>
#include <fstream>
using namespace std;

//文件操作！！！

// 写文件
void test01()
{
    ofstream ofs;
    ofs.open("txt/text.txt", ios::out);
    ofs << "zhansan" << endl;
    ofs << "lisi" << endl;
    ofs << "wangwu" << endl;
    ofs.close();
}

//读文件
void test02()
{

    // 第一种读文件方式
    ifstream ifs;
    ifs.open("txt/text.txt", ios::in);
    if (!ifs.is_open())
    {
        std::cout << "打开失败" << '\n';
        return;
        /* code */
    }
    char buf[1024] = {0};
    while (ifs >> buf)
    {

        std::cout << buf << '\n';
        /* code */
    }
    std::cout << "第一种读取成功" << '\n';
    ifs.close();
}

void test03()
{

    // 第二种读文件方式
    ifstream ifs;
    ifs.open("txt/text.txt", ios::in);
    if (!ifs.is_open())
    {
        std::cout << "打开失败" << '\n';
        return;
        /* code */
    }
    char buf[1024] = {0};
    while (ifs.getline(buf, sizeof(buf)))
    {

        std::cout << buf << '\n';
        /* code */
    }
    std::cout << "第二种读取成功" << '\n';
    ifs.close();
}

void test04()
{

    // 第三种读文件方式
    ifstream ifs;
    ifs.open("txt/text.txt", ios::in);
    if (!ifs.is_open())
    {
        std::cout << "打开失败" << '\n';
        return;
        /* code */
    }
    string buf;
    while (getline(ifs, buf))
    {

        std::cout << buf << '\n';
        /* code */
    }
    std::cout << "第三种读取成功" << '\n';
    ifs.close();
}

//二进制文件读写
class Person
{

public:
    string m_name;
    int m_age;
    /* data */
};

void test05()
{
    ofstream ofs;
    ofs.open("txt/text3.txt", ios::out | ios::binary);
    Person p1;
    p1.m_name = "zhangsan";
    p1.m_age = 18;

    ofs.write((const char *)&p1, sizeof(Person));
    std::cout << "二进制写入成功" << '\n';
    ofs.close();
}

void test06()
{
    ifstream ifs;
    ifs.open("txt/text2.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        std::cout << "打开失败" << '\n';
        return;
        /* code */
    }
    std::cout << "二进制读取成功" << '\n';

    Person p2;
    ifs.read((char *)&p2, sizeof(Person));
    cout << "姓名" << p2.m_name << endl;
    cout << "年龄" << p2.m_age << endl;
    ifs.close();
}

int main()
{
    test06();

    return 0;
}
