#include "InventoryManagementBasic.h"
const int NUM = 4;

int main()
{
    InventoryManagementBasic item;
    UserFunctions instance;
    char keepGoing = 'y';
    while (keepGoing == 'y') {
        instance.userOptions(&item);
        cout << "\nWould you like to do something else (y/n)\n";
        cin >> keepGoing;
    }
}