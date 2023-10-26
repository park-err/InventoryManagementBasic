#include "InventoryManagementBasic.h"

void placeHolder() {
	cout << "\n\nUnder construction, select another option\n\n";
}

void InventoryManagementBasic::userOptions() {
	int input;
	cout << "Pick one:\n";
	cout << "	1. Check inventory\n";
	cout << "	2. Check sales\n";
	cout << "	3. Import sales\n";
	cout << "	4. Export inventory\n";

	cin >> input;

	switch (input)
	{
	case 1:
		placeHolder();
		break;
	case 2:
		placeHolder();
		break;
	case 3:
		placeHolder();
		break;
	case 4:
		placeHolder();
		break;
	default:
		cout << "\n\nInvalid selection: Please select 1, 2, 3, or 4.\n\n";
	}
}