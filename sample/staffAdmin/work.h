#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#define FILENAME "txt/empFile.txt"

class Worker
{
public:
    virtual void showInfo() = 0;
    virtual string getDepName() = 0;

    int m_Id;
    string m_Name;
    int m_DepId;

    virtual ~Worker(); //添加虚析构函数，可以避免delete内存出错
};

class WorkerManager
{
private:
    /* data */
public:
    WorkerManager(/* args */);

    void showMenu();

    void exitSys();

    void addEmp();

    void save();

    int m_EmpNum;
    Worker **m_EmpArry;

    bool m_FileEmpty;
    int getNum();

    void init_Emp();

    void show_Emp();

    void del_Emp();

    void mod_Emp();

    void find_Emp();

    void sort_Emp();

    void clean_File();

    int isEx(int id);

    ~WorkerManager();
};

class Employee : public Worker
{
private:
    /* data */
public:
    Employee(int id, string name, int depId);
    ~Employee();

    virtual void showInfo();
    virtual string getDepName();
};
