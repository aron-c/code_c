#include "work.h"
#include <unistd.h>
#include "manager.h"

WorkerManager::WorkerManager(/* args */)
{
    this->m_EmpNum = 0;
    this->m_EmpArry = NULL;
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

        cout << "成功添加" << addNum << "名新员工" << endl;

        this->save();
    }
    else
    {
        cout << "输入有误，请重新输入！" << endl;
    }
}

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
