#include "InventoryManagementBasic.h"

void placeHolder() {
	cout << "\n\nUnder construction, select another option\n\n";
}

void UserFunctions::genItems(vector<InventoryManagementBasic> *items, fstream &itemsFile) {
	// temp vars
	string description = "undefined"; int count = 0; double cost = 0.0, retail = 0.0;
	
	while (!itemsFile.eof()) {
		itemsFile >> description;
		itemsFile >> count;
		itemsFile >> cost;
		itemsFile >> retail;

		InventoryManagementBasic item(description, count, cost, retail);
		items->push_back(item);
	}

	itemsFile.close();
}

void UserFunctions::createItem(vector<InventoryManagementBasic>* items) {
	// in the future, create item will append an item file
	// the item file will keep track of items created
	// the file will be read and each line will create an instance of Item
	// after the use of the program, the items will be destroyed, until needed again
	
	// cins will only be for console build. Once moved to GUI this will be changed
	string createDescription; int createCount; double createCost, createRetail;
	fstream itemsFile("itemList.txt", std::ios_base::app);

	cout << "Enter item description: ";
	cin >> createDescription;
	cout << "Enter item count: ";
	cin >> createCount;
	cout << "Enter item cost per unit: ";
	cin >> createCost;
	cout << "Enter item retail price per unit: ";
	cin >> createRetail;

	itemsFile << createDescription << endl;
	itemsFile << createCount << endl;
	itemsFile << createCost << endl;
	itemsFile << createRetail << endl;

	itemsFile.close();
	InventoryManagementBasic item(createDescription, createCount, createCost, createRetail);
	items->push_back(item);
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
		createItem(items);
		break;
	case 2:
		for (int i = 0; i < length; i++) {
			cout << "Description: " << (*items)[i].getName() << endl;
			cout << "Count: " << (*items)[i].getCount() << endl;
			cout << "Cost: " << (*items)[i].getCost() << endl;
			cout << "Retail: " << (*items)[i].getRetail() << endl;
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