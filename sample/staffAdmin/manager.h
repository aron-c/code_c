#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "work.h"



class Manager : public Worker
{
private:
    /* data */
public:
    Manager(int id, string name, int depId);
    ~Manager();

    virtual void showInfo();
    virtual string getDepName();
};


class Boss : public Worker
{
private:
    /* data */
public:
    Boss(int id, string name, int depId);
    ~Boss();

    virtual void showInfo();
    virtual string getDepName();
};
