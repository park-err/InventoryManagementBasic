#include "InventoryManagementBasic.h"

int main()
{
    InventoryManagementBasic item;
    char keepGoing = 'y';
    while (keepGoing == 'y') {
        item.userOptions();
        cout << "Would you like to do something else (y/n)";
        cin >> keepGoing;
    }
}