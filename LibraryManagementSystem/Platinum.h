#include "Member.h"

#pragma once
class Platinum:public Member{

public:
	string setMember(string name, string add, string phone, string type, int day, int month, int year, int a, int b, int c, int x, int y, int z){
	
		setId();
		return Member::setMember(name, add, phone, "PLATINUM", day, month, year, 5, 5, 3, 0, 10000, 365);
			
	}	

};
