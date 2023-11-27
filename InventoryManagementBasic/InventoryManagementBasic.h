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
	float itemSKU;
	string itemName;
	int itemCount;
	double itemCost;
	double itemRetail;

public:

	InventoryManagementBasic() {
		itemSKU = 700000;
		itemName = "default_item";
		itemCount = 0;
		itemCost = 0;
		itemRetail = 0;
	}
	
	InventoryManagementBasic(float sku, string name, int count, double cost, double retail) {
		setSKU(sku);
		setName(name);
		setCount(count);
		setCost(cost);
		setRetail(retail);
	}

	~InventoryManagementBasic() {}

	// setter functions
	void setSKU(float sku) {
		itemSKU = sku;
	}
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
	float getSKU() {
		return itemSKU;
	}
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
	int genSales(vector<InventoryManagementBasic> *items);
  
  // create new class for functions below this comment
	int findItemFromSKU(vector<InventoryManagementBasic>* items, float SKU) {
		for (int i = 0; i < items->size(); i++) {
			if ((*items)[i].getSKU() == SKU) {
				return i;
			}
		}

		return -1;
	}
};