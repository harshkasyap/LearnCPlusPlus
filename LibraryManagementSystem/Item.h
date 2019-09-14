#include<string>
#include<exception>
#include<sstream>
using namespace std;

#pragma once
class Item{

private	:
	int id,count;
	static int id_gen;
	string name,type;

public:
	void setType(string);
	void setName(string);
	void setId();
	void setCount(int);
	string getType();
	string getName();
	int getId();
	int getCount();
	int checkAvail();
	virtual string setItem(string,string,string,int)=0;
	virtual string getItem()=0;
	string issueItem();
	string returnItem();

};



 
