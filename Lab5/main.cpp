#include <iostream>
using namespace std;
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"

int main()
{
    char choice;

    while (true)
    {
        cout << "Choose a task (1, 2, 3, 0 to exit): ";
        cin >> choice;
        if (choice == '1')
        {
            runTask1();
        }
        else if (choice == '2')
        {
            runTask2();
        }
        else if (choice == '3')
        {
            runTask3();
        }
        else if (choice == '0')
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
