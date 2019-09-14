#include "Member.h"

#pragma once
class Gold:public Member{

public:
	string setMember(string name, string add, string phone, string type, int day, int month, int year, int a, int b, int c, int x, int y, int z){
	
		setId();
		return Member::setMember(name,add,phone,"GOLD",day,month,year,5,5,0,10,5000,365);
			
	}	

};
