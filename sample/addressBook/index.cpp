#include <iostream>
#include <unistd.h>
#include <string>
#include <term.h>
#include "app.h"
#include "app.cpp"
using namespace std;
#define maxSize 1000

int main()
{

    int select = 0;
    // cout << "hello world!" << endl;
    struct addressBook abs;
    abs.mSize = 0;
    while (true)
    {
        showMenu();

        cin >> select;
        switch (select)
        {
        case 1:
            printf("\x1b[H\x1b[2J");
            addressMember(&abs);
            backMenu();
            // system("clear");
            /* code */
            break;
        case 2:
            printf("\x1b[H\x1b[2J");
            showMember(&abs);
            backMenu();
            /* code */
            break;
        case 3:
        {
            printf("\x1b[H\x1b[2J");
            deMember(&abs);
            backMenu();
            /* code */
            break;
        }
        case 4:
            printf("\x1b[H\x1b[2J");
            findMember(&abs);
            backMenu();
            /* code */
            break;
        case 5:
            printf("\x1b[H\x1b[2J");
            modMember(&abs);
            backMenu();
            /* code */
            break;
        case 6:
            printf("\x1b[H\x1b[2J");
            clsMember(&abs);
            backMenu();
            /* code */
            break;
        case 0:
            cout << "欢迎下次使用！" << endl;
            return 0;
            break;

        default:
            printf("\x1b[H\x1b[2J");
            cout << "重新选择" << endl;
            break;
        } /* code */
    }

    pause();
    return 0;
}
