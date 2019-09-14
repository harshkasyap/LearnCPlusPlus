#include<string>
#include<sstream>
using namespace std;

#pragma once
class DateClass{

private:
	int day,month,year;

public:
	int getDay();
	int getMonth();
	int getYear();
	string setDate(int,int,int);
	string getDate();
	int diffInDate(DateClass);
};
