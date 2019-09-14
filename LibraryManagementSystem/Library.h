#include <iostream>
#include <list>
#include "Book.h"
#include "DVD.h"
#include "Manual.h"
#include "Platinum.h"
#include "Gold.h"
#include "Silver.h"
#include "Issue.h"

using namespace std;
#pragma once
class Library{

private:
	list<Item*> items;
	list<Member*> members;
	list<Issue*> issue;

public:	
	void displayItems();
	void addItem();
	void addMember();
	void displayMembers();
	void closeMember();
	void renewMember();
	void issueItem();
	void returnItem();	
};
