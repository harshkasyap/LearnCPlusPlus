#include "Item.h"

#pragma once
class Book:public Item{
	
private:
	string author,publisher;

public:
	string setItem(string,string,string,int);
	string getItem();
	
};
