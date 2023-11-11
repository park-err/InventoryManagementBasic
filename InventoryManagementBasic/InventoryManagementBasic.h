#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout; using std::cin;	// performance better than namespace
using std::string; using std::fstream;
using std::ios; using std::endl; using std::vector;

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

	~InventoryManagementBasic() {}

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
	void genItems(vector<InventoryManagementBasic>* items, fstream &itemsFile);
	void userOptions(vector<InventoryManagementBasic> *items, int length);
	void createItem(vector<InventoryManagementBasic> *items);
};