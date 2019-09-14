#include<sstream>
#include<string>
#include"DateClass.h"
using namespace std;

#pragma once
class Issue{

private:
	int id,memberId,itemId;
	static int id_gen;
	DateClass issueDate,returnDate;
public:
	int getId();
	int getMemberId();
	int getItemId();
	string showIssue();
	string issueDateFun(int,int,int,int,int);
	string returnDateFun(int,int,int,int);	
};
