#include "Manual.h"
#include "StringException.h"
#include "NumberException.h"

string Manual::setItem(string name,string author,string subject,int count){
	
	if(name.size()==0){
		throw StringException();
	}
	
	if(author.size()==0){
		throw StringException();
	}
	
	if(subject.size()==0){
		throw StringException();
	}

	if (count<1){
		throw NumberException();
	}
	
	setId();
	setCount(count);
	setName(name);
	setType("MANUAL");
	this->author = author;
	this->subject=subject;
	
	string msg="Item succesfully Added";
	return msg;
	
}

string Manual::getItem(){
	
	ostringstream os;
	os << getId();
	string itemDetail="\n";
	itemDetail.append(os.str()+", "+getName()+", "+author+", "+subject+", "+getType()+", ");
	ostringstream os1;
	os1 << getCount();
	itemDetail.append("" + os1.str());
	return itemDetail;
	
}

















