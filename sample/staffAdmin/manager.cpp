#include "manager.h"
#include <unistd.h>

//经理
void Manager::showInfo()
{
    cout << "员工编号：" << this->m_Id << "\t员工姓名：" << this->m_Name << "\t员工岗位：" << this->getDepName() << "\t员工职务：完成老板交给的任务，并下发任务给普通员工" << endl;
}

string Manager::getDepName()
{
    return "经理";
}

Manager::Manager(int id, string name, int depId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = depId;
}

Manager::~Manager()
{
}

//老板
void Boss ::showInfo()
{
    cout << "员工编号：" << this->m_Id << "\t员工姓名：" << this->m_Name << "\t员工岗位：" << this->getDepName() << "\t员工职务：管理公司所有事务" << endl;
}

string Boss ::getDepName()
{
    return "总裁";
}

Boss ::Boss(int id, string name, int depId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = depId;
}

Boss ::~Boss()
{
}