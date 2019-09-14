#include "Item.h"
#pragma once
class DVD:public Item{
	
private:
	string compatibility,creator;

public:
	string setItem(string,string,string,int);
	string getItem();
	
};
