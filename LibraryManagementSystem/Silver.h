#include "Member.h"

#pragma once
class Silver:public Member{

public:
	string setMember(string name,string add,string phone,string type,int day,int month,int year,int a,int b,int c,int x,int y,int z){
	
		setId();
		return Member::setMember(name, add, phone, "SILVER", day, month, year, 5, 0, 0, 10, 1000, 30);
			
	}	

};
