#include <iostream>
#include <unistd.h>
using namespace std;
#include "work.h"
#include "work.cpp"
#include "manager.h"
#include "manager.cpp"
#include <term.h>

//清屏返回
void backMenu()
{

    //实现返回菜单
    cout << "按任意键返回菜单" << endl;
    cin.get();
    cin.get();
    printf("\x1b[H\x1b[2J");
}

int main()
{
    WorkerManager wm;
    int choice = 0;

    // Worker *w = NULL;

    // w = new Employee(1, "zhangsan", 1);
    // w->showInfo();
    // w = new Manager(2, "lisi", 2);
    // w->showInfo();

    // w = new Boss(3, "wangwu", 3);
    // w->showInfo();

    while (true)
    {
        wm.showMenu();
        cout << "请输入你选择的功能序号：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            wm.exitSys();
            /* 退出系统 */
            break;
        case 1:
            wm.addEmp();
            backMenu();
            /* 添加员工 */
            break;
        case 2:

            backMenu();
            /* 显示员工 */
            break;
        case 3:
            /* 删除员工*/
            break;
        case 4:
            /* 修改员工 */
            break;
        case 5:
            /* 查找员工 */
            break;
        case 6:
            /* 排序员工 */
            break;
        case 7:
            /* 清空文档 */
            break;

        default:
            printf("\x1b[H\x1b[2J");
            cout << "重新选择" << endl;
            break;
        }
    }

    pause();
    return 0;
}
