#include<string>
using namespace std;
#pragma once
class StringException:public exception{

public:
	const char* what() const throw(){
		return "You have not put anything.. Plz be honest!!! ";
	}
	
};
