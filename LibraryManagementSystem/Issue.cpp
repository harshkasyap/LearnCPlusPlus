#include "Issue.h"

int Issue::id_gen=100;

int Issue::getId(){
	return id;
}

int Issue::getMemberId(){
	return memberId;
}

int Issue::getItemId(){
	return itemId;
}

string Issue::showIssue(){

	string msg="";
	ostringstream os;
	os << id;
	ostringstream os1;
	os1 << memberId;
	ostringstream os2;
	os2 << itemId;
	msg.append(os.str()+", "+os1.str()+", "+os2.str()+", "+this->issueDate.getDate()+", "+this->returnDate.getDate());
	
	return msg;
}

string Issue::issueDateFun(int memberId,int itemId,int day,int month,int year){

	id=id_gen++;
	DateClass date;
	date.setDate(day,month,year);			
	this->issueDate=date;
	this->memberId=memberId;
	this->itemId=itemId;

	string msg="\nSucessfully Issued..Return within a month!!!";
	return msg;
	
}

string Issue::returnDateFun(int day,int month,int year,int type){

	DateClass date;
	date.setDate(day,month,year);			
	int diff=this->issueDate.diffInDate(date);
	int fine=0;
	if(diff>30 && type!=1){
		fine=(diff-30)*10;
	}
	returnDate=date;
	ostringstream os;
	os << fine;
	
	string msg = "\n";
	msg.append("Sucessfully Returned!!! with fine Rs. " + os.str());
	return msg;

}