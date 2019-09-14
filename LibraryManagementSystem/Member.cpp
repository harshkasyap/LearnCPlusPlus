#include "Member.h"
#include "NumberException.h"
#include "StringException.h"

int Member::id_gen=1000;

void Member::setId(){
	id=id_gen++;
}

int Member::getId(){
	return id;
}

string Member::getType(){
	return type;
}

void Member::setBooksIssued(int count){
	booksIssued+=count;
}
void Member::setDvdsIssued(int count){
	dvdsIssued+=count;
}
void Member::setManualsIssued(int count){
	manualsIssued+=count;
}
int Member::getBooksIssued(){
	return booksIssued;
}
int Member::getDvdsIssued(){
	return dvdsIssued;
}
int Member::getManualsIssued(){
	return manualsIssued;
}
int Member::getNoOfBooks(){
	return noOfBooks;
}
int Member::getNoOfDvds(){
	return noOfDvds;
}
int Member::getNoOfManuals(){
	return noOfManuals;
}
int Member::getFine(){
	return fine;
}
int Member::getRenewalFee(){
	return renewalFee;
}
int Member::getMembershipTime(){
	return membershipTime;
}
int Member::checkMembership(int day,int month,int year){

	DateClass date;
	date.setDate(day,month,year);
	int diff=renewalDate.diffInDate(date);
	if(diff!=-1 && diff<membershipTime){
		return 1;
	}
	else{
		return 0;
	}
		
}

int Member::getStatus(){

	int day = closingDate.getDay();
	int month = closingDate.getMonth();
	int year = closingDate.getYear();

	if (day == 10 && month == 10 && year == 10)
		return 1;
	else 
		return 0;

}

string Member::renewMember(int day,int month,int year){
	string msg="";
	DateClass date;
	date.setDate(day,month,year);
	this->renewalDate=date;			
	msg="\nSucessfully Renewed";
	return msg;
}

string Member::closeMember(int day,int month,int year){
	string msg="";
	DateClass date;
	date.setDate(day,month,year);
	this->closingDate=date;			
	msg="\nSucessfully Closed";
	return msg;	
}

string Member::getMember(){

	string memberInfo="";
	ostringstream os;
	os << id;
	memberInfo.append("\n"+os.str()+", ").append(name+", "+add+", "+phone+", "+type+", "+openingDate.getDate()+", "+renewalDate.getDate()+", "+closingDate.getDate()+", ");
	ostringstream os1;
	os1 << noOfBooks;
	ostringstream os2;
	os2 << noOfDvds;
	ostringstream os3;
	os3 << noOfManuals;
	ostringstream os4;
	os4 << fine;
	ostringstream os5;
	os5 << renewalFee;
	ostringstream os6;
	os6 << membershipTime;
	memberInfo.append(os1.str()+", "+os2.str()+", "+os3.str()+", "+os4.str()+", "+os5.str()+", "+os6.str());
	
	return memberInfo;
}

string Member::setMember(string name,string add,string phone,string type,int day,int month,int year,int noOfBooks,int noOfDvds,int noOfManuals,int fine,int renewalFee,int membershipTime){

	string msg="";
	
	DateClass date;
	date.setDate(day,month,year);
		
	DateClass closeDate;
	closeDate.setDate(10,10,10);

	if(name.size()==0){
		throw StringException();
	}
	if(add.size()==0){
		throw StringException();
	}
	if(phone.size()==0){
		throw StringException();
	}
	if(type.size()==0){
		throw StringException();
	}
	if(noOfBooks<0){
		throw NumberException();
	}
	if(noOfDvds<0){
		throw NumberException();
	}
	if(noOfManuals<0){
		throw NumberException();
	}
	if(fine<0){
		throw NumberException();
	}
	if(renewalFee<0){
		throw NumberException();
	}
	if(membershipTime<0){
		throw NumberException();
	}
	
	this->name=name;
	this->add=add;
	this->phone=phone;
	this->type=type;
	this->noOfBooks=noOfBooks;
	this->noOfDvds=noOfDvds;
	this->noOfManuals=noOfManuals;
	this->fine=fine;
	this->renewalFee=renewalFee;
	this->membershipTime=membershipTime;
	this->openingDate=date;
	this->renewalDate=date;
	this->closingDate = closeDate;


	msg="\n!Sucessfully Added As New Member... Welcome To This Community And Enjoy Reading";
	return msg;
}






