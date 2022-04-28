#include "work.h"
#include <unistd.h>
#include "manager.h"

Worker::~Worker(){}; //添加虚析构函数，可以避免delete内存出错

WorkerManager::WorkerManager(/* args */)
{
    // 1.初始化第一种：文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        // cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArry = NULL;
        this->m_FileEmpty = true;
        ifs.close();
        return;
    }

    // 2.初始化第二种：文件存在，但为空
    char ch;
    ifs >> ch;     //打开文件右移一个字符
    if (ifs.eof()) // ifs字符判断是否为eof()标志
    {
        // cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArry = NULL;
        this->m_FileEmpty = true;
        ifs.close();
        return;
    }

    // 3.初始化第三种，文件存在，不为空，有数据
    int num = this->getNum();
    // cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;
    this->m_FileEmpty = false;

    this->m_EmpArry = new Worker *[this->m_EmpNum];
    this->init_Emp();

    // for (int i = 0; i < this->m_EmpNum; i++)
    // {
    //     cout << "员工编号：" << this->m_EmpArry[i]->m_Id << "\t员工姓名：" << this->m_EmpArry[i]->m_Name << "\t员工岗位：" << this->m_EmpArry[i]->m_DepId << endl;
    // }

    // this->m_EmpNum = 0;
    // this->m_EmpArry = NULL;
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArry != NULL)
    {
        delete[] this->m_EmpArry;
        this->m_EmpArry = NULL;
    }
}

//显示菜单
void WorkerManager::showMenu()
{
    cout << "************************************" << endl;
    cout << "*******欢迎使用职工管理系统！*******" << endl;
    cout << "**********0.退出管理系统************" << endl;
    cout << "**********1.增加职工信息************" << endl;
    cout << "**********2.显示职工信息************" << endl;
    cout << "**********3.删除职工信息************" << endl;
    cout << "**********4.修改职工信息************" << endl;
    cout << "**********5.查找职工信息************" << endl;
    cout << "**********6.按照编号排序************" << endl;
    cout << "**********7.清空员工列表************" << endl;

    cout << "************************************" << endl;
    cout << endl;
}

//退出系统
void WorkerManager::exitSys()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

//添加员工
void WorkerManager::addEmp()
{
    cout << "请输入添加职工数量：" << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        //计算添加空间的大小
        int newSize = this->m_EmpNum + addNum;

        //开辟新空间
        Worker **newSpace = new Worker *[newSize];

        //将原来的空间下的数据保存在当前堆空间下
        if (this->m_EmpArry != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArry[i];
                /* code */
            }
        }

        //添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dS;

            cout << "请输入第" << i + 1 << "个新员工的编号是：" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个新员工的姓名是：" << endl;
            cin >> name;

            cout << "请输入第" << i + 1 << "个新员工的岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.总裁" << endl;
            cin >> dS;

            Worker *worker = NULL;
            switch (dS)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;

            default:
                cout << "输入错误，请重新输入!" << endl;
                break;
            }

            //将worker*保存到数组
            newSpace[this->m_EmpNum + i] = worker;
        }

        //删除原有的空间数组
        delete[] this->m_EmpArry;

        //更改新空间指向，记录newspace
        this->m_EmpArry = newSpace;

        //更新员工人数，记录newsize
        this->m_EmpNum = newSize;

        //改变为空标志
        this->m_FileEmpty = false;
        cout << "成功添加" << addNum << "名新员工" << endl;

        this->save();
    }
    else
    {
        cout << "输入有误，请重新输入！" << endl;
    }
}

//用文件保存员工
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArry[i]->m_Id << " " << this->m_EmpArry[i]->m_Name << " " << this->m_EmpArry[i]->m_DepId << endl;
    }

    ofs.close();
}

//获得已有文件内的员工数
int WorkerManager::getNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int Did;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> Did)
    {
        num++; /* code */
        //统计人数
    }
    ifs.close();
    return num;
}

//将文件内的员工初始化进存储中
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;
        if (dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }

        this->m_EmpArry[index] = worker;
        index++;
    }

    ifs.close();
}

//显示所有职工
void WorkerManager::show_Emp()
{
    if (this->m_FileEmpty)
    {
        cout << "文件不存在，或文件为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArry[i]->showInfo();
        }
    }
}

//判断职工是否存在，存在返回位置，不存在返回-1
int WorkerManager::isEx(int id)
{
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArry[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

//删除该编号职工
void WorkerManager::del_Emp()
{
    if (this->m_FileEmpty)
    {
        cout << "文件不存在，或文件为空" << endl;
    }
    else
    {
        cout << "请输入要删除职工编号：" << endl;
        int id;
        cin >> id;
        int index = this->isEx(id);

        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArry[i] = this->m_EmpArry[i + 1]; //数据迁移
            }
            //总数-1
            this->m_EmpNum--;

            //保存到文件中
            this->save();
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败，未找到职工" << endl;
        }
    }
}

//修改员工信息
void WorkerManager::mod_Emp()
{
    if (this->m_FileEmpty)
    {
        cout << "文件不存在，或文件为空" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int index = this->isEx(id);

        if (index != -1)
        {
            delete this->m_EmpArry[index];

            int newId = 0;
            string newName = "";
            int newdS = 0;

            cout << "查找到编号为：" << id << " 的员工，"
                 << "请输入新的职工编号：" << endl;
            cin >> newId;

            cout << "请输入新的职工姓名：" << endl;
            cin >> newName;

            cout << "请输入新的职工岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.总裁" << endl;
            cin >> newdS;

            Worker *worker = NULL;
            switch (newdS)
            {
            case 1:
                worker = new Employee(newId, newName, 1);
                break;
            case 2:
                worker = new Manager(newId, newName, 2);
                break;
            case 3:
                worker = new Boss(newId, newName, 3);
                break;

            default:
                cout << "输入错误，请重新输入!" << endl;
                break;
            }

            //将修改内容添加到原指针数组中，更新数据
            this->m_EmpArry[index] = worker;
            cout << "成功修改" << endl;

            this->save();
        }
        else
        {
            cout << "未找到职工" << endl;
        }
    }
}

//查找员工。1编号.2姓名
void WorkerManager::find_Emp()
{
    if (this->m_FileEmpty)
    {
        cout << "文件不存在，或文件为空" << endl;
    }
    else
    {
        //选择查找方式
        cout << "选择查找方式：" << endl;
        cout << "1.按照编号查找" << endl;
        cout << "2.按照姓名查找：" << endl;
        int select;
        cin >> select;

        if (select == 1)
        {
            cout << "请输入要查找的员工编号：" << endl;
            int id;
            cin >> id;

            int index = this->isEx(id);
            if (index != -1)
            {
                cout << "查找成功！该员工信息如下" << endl;
                this->m_EmpArry[index]->showInfo();
            }
            else
            {
                cout << "查找失败！请重试" << endl;
            }
        }
        else if (select == 2)
        {
            cout << "请输入要查找的员工姓名：" << endl;
            string name;
            cin >> name;

            //查找标志，如果有重名，可以查询多个
            //若是没有，标志为false，会返回查找失败
            bool flag = false;

            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArry[i]->m_Name == name)
                {
                    cout << "查找成功！该员工信息如下" << endl;
                    this->m_EmpArry[i]->showInfo();
                    flag = true;
                }

                //不能用else判断，找不到会一直else
            }

            if (flag == false)
            {
                cout << "查找失败！请重试" << endl;
            }
        }
        else
        {
            cout << "输入错误，请重试！" << endl;
        }
    }
}

//将员工按照编号排序
void WorkerManager::sort_Emp()
{

    if (this->m_FileEmpty)
    {
        cout << "文件不存在，或文件为空" << endl;
    }
    else
    {
        cout << "请选择排序方式：" << endl;
        cout << "1.按照升序排列" << endl;
        cout << "2.按照降序排列" << endl;
        int select;
        cin >> select;

        if (select == 1)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                int minIndex = i;
                for (int j = i + 1; j < this->m_EmpNum; j++)
                {
                    if (this->m_EmpArry[minIndex]->m_Id > this->m_EmpArry[j]->m_Id)
                    {
                        minIndex = j;
                    }
                }

                if (i != minIndex)
                {
                    Worker *temp = this->m_EmpArry[i];
                    this->m_EmpArry[i] = this->m_EmpArry[minIndex];
                    this->m_EmpArry[minIndex] = temp;
                }
            }
        }
        else if (select == 2)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                int maxIndex = i;
                for (int j = i + 1; j < this->m_EmpNum; j++)
                {
                    if (this->m_EmpArry[maxIndex]->m_Id < this->m_EmpArry[j]->m_Id)
                    {
                        maxIndex = j;
                    }
                }

                if (i != maxIndex)
                {
                    Worker *temp = this->m_EmpArry[i];
                    this->m_EmpArry[i] = this->m_EmpArry[maxIndex];
                    this->m_EmpArry[maxIndex] = temp;
                }
            }
        }
        else
        {
            cout << "输入错误，请重试！" << endl;
        }
        this->save();
        this->show_Emp();
    }
}

//清空文件系统
void WorkerManager::clean_File()
{
    cout << "确定是否清空所有文件内容？" << endl;
    cout << " 1.是" << endl;
    cout << " 2.否" << endl;
    int select;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs;
        ofs.open(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArry != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArry[i];
                this->m_EmpArry[i] = NULL;
            }

            this->m_EmpArry = NULL;
            this->m_EmpNum = 0;
            this->m_FileEmpty = true;
        }

        cout << "已清空文件！" << endl;
    }
    else
    {
        cout << "请重新选择" << endl;
    }
}
//显示个人信息
void Employee::showInfo()
{
    cout << "员工编号：" << this->m_Id << "\t员工姓名：" << this->m_Name << "\t员工岗位：" << this->getDepName() << "\t员工职务：完成经理交给的任务" << endl;
}

string Employee::getDepName()
{
    return "员工";
}

Employee::Employee(int id, string name, int depId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = depId;
}

Employee::~Employee()
{
}
