#include "InventoryManagementBasic.h"
const int NUM = 1;

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
        cout << "Name retrieved";
        itemsFile >> count;
        cout << "Count retrieved";
        itemsFile >> cost;
        cout << "Cost retrieved";
        itemsFile >> retail;    // will need to implement file verification
        cout << "Retail retrieved";
    }

    vector<InventoryManagementBasic> *items = new vector<InventoryManagementBasic>(NUM);
    UserFunctions instance;
    cout << "Ready for initialization ..................";
    instance.genItems(items, NUM, name, count, cost, retail);
    char keepGoing = 'y';
    while (keepGoing == 'y') {
        instance.userOptions(items, 1);
        cout << "\nWould you like to do something else (y/n)\n";
        cin >> keepGoing;
    }

    delete items;
    return 0;
}