#include<string>
using namespace std;
#pragma once
class NumberException:public exception{

public:
	const char* what() const throw(){
		return "\nYou have not put a valid number.. Plz be honest!!! ";
	}
	
};
