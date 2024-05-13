#include "InventoryManagementBasic.h"
const int NUM = 1;

int main()
{
    fstream itemsFile("itemList.txt", ios::in);

    // end session if file can't be opened
    if (!itemsFile) {
        cout << "Fatal Error: Could not initialize data.";
        return 30;
    }

    // need file verification

    vector<InventoryManagementBasic> *items = new vector<InventoryManagementBasic>();
    UserFunctions instance;
    instance.genItems(items, itemsFile);
    char keepGoing = 'y';
    while (keepGoing == 'y') {
        instance.userOptions(items, items->size());
        cout << "\nWould you like to do something else (y/n)\n";
        cin >> keepGoing;
    }

    delete items;
    return 0;
}