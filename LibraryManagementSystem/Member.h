#include<string>
#include<exception>
#include<sstream>
#include"DateClass.h"
using namespace std;

#pragma once
class Member{

private	:
	int id,noOfBooks,noOfDvds,noOfManuals,fine,renewalFee,membershipTime,booksIssued=0,dvdsIssued=0,manualsIssued=0;
	static int id_gen;
	string name,add,phone,type;
	DateClass openingDate,closingDate,renewalDate; 

public:
	void setId();
	int getId();
	string getType();
	string getMember();
	int getBooksIssued();
	int getDvdsIssued();
	int getManualsIssued();
	void setBooksIssued(int);
	void setDvdsIssued(int);
	void setManualsIssued(int);
	int getNoOfBooks();
	int getNoOfDvds();
	int getNoOfManuals();
	int getFine();
	int getRenewalFee();
	int getMembershipTime();			
	int getStatus();
	int checkMembership(int,int,int);
	virtual string setMember(string,string,string,string,int,int,int,int,int,int,int,int,int);
	string closeMember(int,int,int);
	string renewMember(int,int,int);
};

 
