#include "Item.h"
#pragma once
class Manual:public Item{
	
private:
	string author,subject;

public:
	string setItem(string,string,string,int);
	string getItem();
	
};
