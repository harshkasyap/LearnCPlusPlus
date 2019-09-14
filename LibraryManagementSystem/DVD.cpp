#include "DVD.h"
#include "StringException.h"
#include "NumberException.h"

string DVD::setItem(string name,string compatibility,string creator,int count){
	
	if(name.size()==0){
		throw StringException();
	}
	
	if(compatibility.size()==0){
		throw StringException();
	}
	
	if (count<1){
		throw NumberException();
	}

	setId();
	setCount(count);
	setName(name);
	setType("DVD");
	this->compatibility=compatibility;
	this->creator = creator;

	string msg="Item succesfully Added";
	return msg;
}

string DVD::getItem(){
	
	ostringstream os;
	os << getId();
	string itemDetail="\n";
	itemDetail.append(os.str()+", "+getName()+", "+creator+", "+compatibility+", "+getType()+", ");
	ostringstream os1;
	os1 << getCount();
	itemDetail.append("" + os1.str());
	return itemDetail;
	
}
