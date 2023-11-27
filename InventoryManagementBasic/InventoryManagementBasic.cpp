#include "InventoryManagementBasic.h"

void placeHolder() {
	cout << "\n\nUnder construction, select another option\n\n";
}

int findMidPoint(int min, int max) {
	return ((max + min) / 2);
}

int binarySearch(float key, vector<InventoryManagementBasic>* items, int min, int max) {
	if (max < min || key > items->back().getSKU() || key < items->front().getSKU()) {
		return -1;
	}
	else {
		int midpoint = findMidPoint(min, max);
		int vecMid = (*items)[midpoint].getSKU();

		if (vecMid < key) {
			binarySearch(key, items, ++midpoint, max);
		}
		else if (vecMid > key) {
			binarySearch(key, items, min, --midpoint);
		}
		else {
			return midpoint;
		}
	}
}

void UserFunctions::genItems(vector<InventoryManagementBasic> *items, fstream &itemsFile) {
	// temp vars
	float sku = 0; string description = "undefined"; int count = 0; double cost = 0.0, retail = 0.0;
	
	while (!itemsFile.eof()) {
		itemsFile >> sku;
		itemsFile >> description;
		itemsFile >> count;
		itemsFile >> cost;
		itemsFile >> retail;

		InventoryManagementBasic item(sku, description, count, cost, retail);
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

	float createSKU = (items->back().getSKU()) + 1;
	itemsFile << createSKU << endl;
	itemsFile << createDescription << endl;
	itemsFile << createCount << endl;
	itemsFile << createCost << endl;
	itemsFile << createRetail << endl;

	itemsFile.close();
	InventoryManagementBasic item(createSKU, createDescription, createCount, createCost, createRetail);
	items->push_back(item);
}

int UserFunctions::genSales(vector<InventoryManagementBasic>* items) {
	// will read a file instead
	// mapping out basic functionality
	// FIXME: FILE VALIDATION | CHARS WILL BREAK
	float tempSKU; int tempSold; double tempRev;
	vector<float> soldSKU; vector<int> quantitySold; vector<double> revenue;
	fstream salesFile("salesFileEx.txt", ios::in);
	fstream itemsFile("itemList.txt", std::ios_base::app);

	if (!salesFile || !itemsFile) {
		// if items file cannot be opened, program should not progess this far
		cout << "Error: No sales file detected";
		return 0;
	}
	else {
		while (!salesFile.eof()) {
			salesFile >> tempSKU;
			salesFile >> tempSold;
			salesFile >> tempRev;

			int selectedSKU = binarySearch(tempSKU, items, 0, items->size());
			if (selectedSKU == -1) {
				cout << "\n\nERROR: File contains SKU that does not exist\n";
				return 0;
			}

			soldSKU.push_back(tempSKU);
			quantitySold.push_back(tempSold);
			revenue.push_back(tempRev);
		}
	}

	// maybe add a function to call that will find item based on sku
	for (int i = 0; i < soldSKU.size(); i++) {
		if (findItemFromSKU(items, soldSKU[i]) < 0) {
			cout << "\n\nERROR: File contains SKU that does not exist\n";
			return 0;
		}
		else {
			int j = findItemFromSKU(items, soldSKU[i]);
			double expected = quantitySold[i] * ((*items)[j].getRetail());
			double discount = revenue[i] - expected;

			// will write to a file. file can be referenced when running reports
			cout << "Item sold: " << (*items)[j].getName() << endl;
			cout << "Retail: " << expected << endl;
			cout << "Discount: " << discount << endl;
			cout << "Revenue: " << revenue[i] << endl;

			// quantities will be subtracted from respective items
		}
	}
	itemsFile.close();
	salesFile.close();
	return 1;
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
			cout << "\nSKU: " << (*items)[i].getSKU() << endl;
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
		genSales(items);
		break;
	case 5:
		placeHolder();
		break;
	default:
		cout << "\n\nInvalid selection: Please select 1, 2, 3, or 4.\n\n";
	}
}