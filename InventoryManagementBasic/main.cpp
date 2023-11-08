#include "InventoryManagementBasic.h"
const int NUM = 4;

int main()
{
    fstream itemsFile("itemList.txt", ios::in);
    // temp vars
    string name = "undefined"; int count = 0; double cost = 0.0, retail = 0.0;

    // end session if file can't be opened
    if (!itemsFile) {
        cout << "Fatal Error: Could not access data";
        return 0;
    }

    // if file is discoverable...
    while (!itemsFile.eof()) {
        itemsFile >> name;
        itemsFile >> count;
        itemsFile >> cost;
        itemsFile >> retail;    // will need to implement file verification
    }
    InventoryManagementBasic item(name, count, cost, retail);
    UserFunctions instance;
    char keepGoing = 'y';
    while (keepGoing == 'y') {
        instance.userOptions(&item);
        cout << "\nWould you like to do something else (y/n)\n";
        cin >> keepGoing;
    }

    return 0;
}