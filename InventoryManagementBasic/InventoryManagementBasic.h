#pragma once
#include <iostream>
#include <string>
using namespace std;

class InventoryManagementBasic {
private:
	string itemName;
	int itemCount;
	double itemCost;
	double itemRetail;

public:

	InventoryManagementBasic() {
		itemName = "default_item";
		itemCount = 0;
		itemCost = 0;
		itemRetail = 0;
	}
	
	InventoryManagementBasic(string name, int count, double cost, double retail) {
		setName(name);
		setCount(count);
		setCost(cost);
		setRetail(retail);
	}

	~InventoryManagementBasic() {
		cout << "Item deleted\n";
	}

	// setter functions
	void setName(string name) {
		itemName = name;
	}
	void setCount(int count) {
		itemCount = count;
	}
	void setCost(double cost) {
		itemCost = cost;
	}
	void setRetail(double retail) {
		itemRetail = retail;
	}

	// getter functions
	string getName() {
		return itemName;
	}

	int getCount() {
		return itemCount;
	}
	double getCost() {
		return itemCost;
	}
	double getRetail() {
		return itemRetail;
	}

};

class UserFunctions {
private:
public:
	// cpp functions
	void userOptions(InventoryManagementBasic *item);
	void createItem();
};