#include "Book.h"
#include "StringException.h"
#include "NumberException.h"

string Book::setItem(string name,string author,string publisher,int count){
	
	if(name.size()==0){
		throw StringException();
	}
	
	if(author.size()==0){
		throw StringException();
	}
	
	if(publisher.size()==0){
		throw StringException();
	}
	
	if(count<1){
		throw NumberException();
	}
	
	setId();
	setCount(count);
	setName(name);
	setType("BOOK");
	this->author=author;
	this->publisher=publisher;
	
	string msg="Item succesfully Added";
	return msg;
}

string Book::getItem(){

	ostringstream os;
	os << getId();
	string itemDetail="\n";
	itemDetail.append(os.str()+", "+getName()+", "+author+", "+publisher+", "+getType()+", ");
	ostringstream os1;
	os1 << getCount();
	itemDetail.append(""+os1.str());
	return itemDetail;
	
}



	













