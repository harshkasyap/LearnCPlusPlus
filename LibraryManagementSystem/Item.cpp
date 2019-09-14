#include "Item.h"
#include<exception>

int Item::id_gen=0;	

int Item::getId(){
	return id;
}

int Item::getCount(){
	return count;
}

string Item::getName(){
	return name;
}

string Item::getType(){
	return type;
}

void Item::setCount(int count){
	this->count = count;
}

void Item::setType(string type){
	this->type = type;
}

void Item::setName(string name){
	this->name = name;
}

void Item::setId(){
	this->id = id_gen++;
}

int Item::checkAvail(){
	return count;
}

string Item :: issueItem(){

	string msg="";
	
	if(count>0){
		count--;
		msg="succesfully Issued..!";
		return msg;
	}
	else{
		msg="Not Available";
		return msg;
	}
	
}


string Item :: returnItem(){

	string msg="";
	count++;
	msg="succesfully Returned..!";
	return msg;

}
