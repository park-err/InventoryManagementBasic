#include "InventoryManagementBasic.h"

void placeHolder() {
	cout << "\n\nUnder construction, select another option\n\n";
}

void UserFunctions::genItems(vector<InventoryManagementBasic> *items, int length, string name, int count, double cost, double retail) {
	for (int i = 0; i < length; i++) {
		(*items)[i].setName(name);
		(*items)[i].setCount(count);
		(*items)[i].setCost(cost);
		(*items)[i].setRetail(retail);
	}
}

void UserFunctions::createItem(vector<InventoryManagementBasic>* items) {
	// in the future, create item will append an item file
	// the item file will keep track of items created
	// the file will be read and each line will create an instance of Item
	// after the use of the program, the items will be destroyed, until needed again
	
	// cins will only be for console build. Once moved to GUI this will be changed
	string createName; int createCount; double createCost, createRetail;
	
	cout << "Create Item\nDescription: ";
	cin >> createName;
	cout << "Count: ";
	cin >> createCount;
	cout << "Cost: ";
	cin >> createCost;
	cout << "Retail: ";
	cin >> createRetail;
}

// menu

void UserFunctions::userOptions(vector<InventoryManagementBasic>* items, int length) {
	int input;
	cout << "Pick one:\n";
	cout << "	1. Create item\n";
	cout << "	2. Check inventory\n";
	cout << "	3. Check sales\n";
	cout << "	4. Import sales\n";
	cout << "	5. Export inventory\n";

	cin >> input;

	switch (input)
	{
	case 1:
		placeHolder();
		break;
	case 2:
		for (int i = 0; i < length; i++) {
			cout << (*items)[i].getName();
			cout << (*items)[i].getCount();
			cout << (*items)[i].getCost();
			cout << (*items)[i].getRetail();
		}
		break;
	case 3:
		placeHolder();
		break;
	case 4:
		placeHolder();
		break;
	case 5:
		placeHolder();
		break;
	default:
		cout << "\n\nInvalid selection: Please select 1, 2, 3, or 4.\n\n";
	}
}