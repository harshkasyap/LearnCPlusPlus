#include "Library.h"

void Library::displayItems(){

	for(Item *item : items){
		if (item->getType().compare("BOOK") == 0){
			cout << "\nId,Name,Author,Publisher,AvailableCopies";
		}
		if (item->getType().compare("DVD") == 0){
			cout << "\nId,Name,Compatibility,Creator,AvailableCopies";
		}
		if (item->getType().compare("MANUAL") == 0){
			cout << "\nId,Name,Author,Subject,AvailableCopies";
		}
		cout<<item->getItem();
	}

}

void Library::displayMembers(){
	cout << "\nId,Name,Address,Phone,AccountType,OpeningDate,RenewalDate,ClosingDate,Books,Dvds,Manuals,fine,renewalFee,membershipValidity\n";
	for(Member *member : members){
		cout<<member->getMember();
	}

}

void Library::returnItem(){

	Issue *iss=NULL;
	cout << "\nIssueId,MemberId,BookId,IssueDate,ReturnDate	\n";
	for(Issue *is : issue){
		cout<<is->showIssue();
	}
	
	int id;
	cout<<"\nEnter issueId to be returned..!";
	cin>>id;
	
	int flagId=0;
	for(Issue *is : issue){
		if(is->getId()==id){
			flagId=1;
			iss=is;
			break;
		}
	}
	
	if(flagId==1){
		int day,month,year;
		cout << "\nEnter Day,Month,year(All by pressing enter)";
		cin >> day>>month>>year;

		
		int type=0;
		Member *member=NULL;
		for(Member *m : members){
			if(m->getId()==iss->getMemberId()){
				if(m->getType().compare("PLATINUM")==0){
					type=1;
				}	
				member=m;			
				break;
			}
		}
		
		for(Item *item : items){
			if(item->getId()==iss->getItemId()){
				if(item->getType().compare("BOOK")==0){
					member->setBooksIssued(-1);
				}
				if(item->getType().compare("DVD")==0){
					member->setDvdsIssued(-1);
				}
				if(item->getType().compare("MANUAL")==0){
					member->setManualsIssued(-1);
				}
				cout<<item->returnItem();
				break;
			}
		}
		
		cout<<iss->returnDateFun(day,month,year,type);
	}
	else{
		cout<<"\n You have put something wrong";
	}

}

void Library::issueItem(){

try{
	list<Item *>item;
	int itemChoice;
	cout<<"\nEnter type of Items You want to issue\n1.Books\t2.Dvds\t3.Reference Manuals\t4.Return Back!";
	cin>>itemChoice;
		
	switch(itemChoice){
	
	case 1:
	{
		for(Item *im : items){
			if(im->getType().compare("BOOK")==0){
				item.push_back(im);
			}
		}
	}
			break;
	case 2:
	{
		for(Item *im : items){
			if(im->getType().compare("DVD")==0){
				item.push_back(im);
			}
		}
	}
			break;
	case 3:
	{
		for(Item *im : items){
			if(im->getType().compare("MANUAL")==0){
				item.push_back(im);
			}
		}
	}
			break;
	case 4:
	{
		return;
	}
			break;
	default:
	{
		cout << "\nInvalid Choice..!";
	}
			break;
	
	}
	
	cout<<"\nDisplaying Your Choice...!";
	for(Item *it : item){
		cout<<it->getItem();
	}

	int itemId,flagIid=0;
	cout<<"\nEnter ItemId which you want to issue?";
	cin>>itemId;
	Item *itemItem=NULL;
	for(Item *item : item){
		if(itemId==item->getId()){
			itemItem=item;
			flagIid=1;
			break;
		}
	}
	if(flagIid==1){
		cout<<"\nThe Item Details\n"+itemItem->getItem();
		if(itemItem->checkAvail()){
			int userId,flagId=0;
			cout<<"\n Enter Your Id..!";
			cin>>userId;

			Member *member=NULL;
			for(Member *m : members){
				if(m->getId()==userId){
					member=m;
					flagId=1;
					break;
				}
			}
			
			if (flagId == 1){

				if (member->getStatus())
				{

					int day, month, year;
					cout << "\nEnter Day,Month,year(All by pressing enter)";
					cin >> day >> month >> year;
					if (member->checkMembership(day, month, year)){
						int issued = 0, total = 0;
						if (itemChoice == 1){
							issued = member->getBooksIssued();
							total = member->getNoOfBooks();
						}
						if (itemChoice == 2){
							issued = member->getDvdsIssued();
							total = member->getNoOfDvds();
						}
						if (itemChoice == 3){
							issued = member->getManualsIssued();
							total = member->getNoOfManuals();
						}

						if (issued < total){
							cout << "\nYou have been sucessfully issued the book!! Collect It from counter!";
							Issue *is = new Issue();
							cout << itemItem->issueItem();
							cout << is->issueDateFun(userId, itemId, day, month, year);
							issue.push_back(is);
							if (itemChoice == 1){
								member->setBooksIssued(1);
							}
							if (itemChoice == 2){
								member->setDvdsIssued(1);
							}
							if (itemChoice == 3){
								member->setManualsIssued(1);
							}
						}
						else{
							cout << "\nFirst Return The Books You have already been issued..!";
						}
					}
					else{
						cout << "\nYou are running out of contract.. pLZ Renew your account";
					}
				}
				else{
					cout << "\nEntered Wrong userId..! Sorry Try Again";
				}
			}
			else{
				cout << "Your account has been permanently closed.. Plz renew..!";
			}
		}
		else{
			cout<<"Book Is Not available currently";		
		}
	}
	else{
		cout<<"\nIncorrect Id entered by you...!";
	}
	
}
catch(exception &e){
	cout<<e.what();
}

}

void Library::renewMember(){

try{
	int id,flag=0;
	cout<<"Enter Your Id";
	cin>>id;
	
	Member *member=NULL;
	for(Member *m : members){
		if(m->getId()==id){
			member=m;
			flag=1;
			break;
		}
	}
	
	if(flag==1){
		cout<<"\n"<<member->getMember();
		int day,month,year;
		cout << "\nEnter Day,Month,year(All by pressing enter)";
		cin >> day>>month>>year;
		
		char ans='n';
		cout<<"\n"<<member->getMember();
		cout<<"\nYou will have to pay a small amount of "+member->getRenewalFee();
		cout << "\n are You sure to renew your Account?(y/n)";
		if(ans=='y'){
			cout<<"\n"<<member->renewMember(day,month,year);
		}
		else{
			cout<<"\nWe alaways welcome you again!";
		}
	}
	else{
		cout << "\nSorry... Not Found A Match!!";
	}
	
}
catch(exception &e){
	cout<<e.what();
}
	
}


void Library::closeMember(){

try{
	int id,flag=0;
	cout<<"Enter Your Id";
	cin>>id;
	
	Member *member=NULL;
	for(Member *m : members){
		if(m->getId()==id){
			member=m;
			flag=1;
			break;
		}
	}
	
	if(flag==1){
		cout<<"\n"<<member->getMember();
		int day,month,year;
		cout << "\nEnter Day,Month,year(All by pressing enter)";
		cin >> day>>month>>year;
		
		char ans='n';
		cout<<"\n"<<member->getMember();
		cout << "\n are You sure to delete your Account?(y/n)";
		if(ans=='y'){
			cout<<"\n"<<member->closeMember(day,month,year);
		}
		else{
			cout<<"\nThank You To being an internal member of Our Library!";
		}
	}
	else{
		cout << "\nSorry... Not Found A Match!!";
	}
}
catch(exception &e){
	cout<<e.what();
}

}

void Library::addMember(){

try{
	int itemChoice;
	cout<<"\nEnter type of Membership You want to Join\n1.Platinum\t2.Gold\t3.Silver\t4.Return Back!";
	cin>>itemChoice;
	
	string name,add,phone;
	int day,month,year;
	
	cout << "\nEnter Your Name";
	cin.sync();
	getline(cin, name);
	cout << "\nEnter Address";
	cin.sync();
	getline(cin, add);
	cout << "\nEnter Phone Number";
	cin.sync();
	getline(cin, phone);
	cout << "\nEnter Day,Month,year(All by pressing enter)";
	cin >> day>>month>>year;
	
	switch(itemChoice){
	
	case 1:
	{
		Member *member1 = new Platinum();
		cout << "\n" << member1->setMember(name,add,phone,"",day,month,year,0,0,0,0,0,0);
		cout<<"\nYou will have to pay a small amount of "<<member1->getRenewalFee();
		members.push_back(member1);
	}
			break;
	case 2:
	{
		Member *member2 = new Gold();
		cout << "\n" << member2->setMember(name,add,phone,"",day,month,year,0,0,0,0,0,0);
		cout<<"\nYou will have to pay a small amount of "<<member2->getRenewalFee();
		members.push_back(member2);
	}
			break;
	case 3:
	{
		Member *member3 = new Silver();
		cout << "\n" << member3->setMember(name,add,phone,"",day,month,year,0,0,0,0,0,0);
		cout<<"\nYou will have to pay a small amount of "<<member3->getRenewalFee();
		members.push_back(member3);
	}
			break;
	case 4:
	{
		return;
	}
			break;
	default:
	{
		cout << "\nInvalid Choice..!";
	}
			break;
	
	}
}
catch(exception &e){
	cout<<e.what();
}

}

void Library::addItem(){

try{
	int itemChoice;
	cout<<"\nEnter type of item You want to Add\n1.Book\t2.DVD\t3.Reference Manuals\t4.Return Back!";
	cin>>itemChoice;
	
	string name,author,publisher,subject,creator,compatibility;
	int count;
	
	switch(itemChoice){
	
	case 1:
	{
		Item *item1 = new Book();
		cout << "\nEnter Book Name";
		cin.sync();
		getline(cin, name);
		cout << "\nEnter Author Name";
		cin.sync();
		getline(cin, author);
		cout << "\nEnter Publisher Name";
		cin.sync();
		getline(cin, publisher);
		cout << "\nEnter Number Of Copies";
		cin >> count;
		cout << "\n" << item1->setItem(name, author, publisher, count);
		items.push_back(item1);
	}
			break;
	case 2:
	{
		Item *item2 = new DVD();
		cout << "\nEnter DVD Name";
		cin.sync();
		getline(cin, name);
		cout << "\nEnter Compatibility Name";
		cin.sync();
		getline(cin, compatibility);
		cout << "\nEnter Creator Name";
		cin.sync();
		getline(cin, creator);
		cout << "\nEnter Number Of Copies";
		cin >> count;
		cout << "\n" << item2->setItem(name, compatibility, creator, count);
		items.push_back(item2);
	}
			break;
	case 3:
	{
		Item *item3 = new Manual();
		cout << "\nEnter Manual Name";
		cin.sync();
		getline(cin, name);
		cout << "\nEnter Author Name";
		cin.sync();
		getline(cin, author);
		cout << "\nEnter Publisher Name";
		cin.sync();
		getline(cin, publisher);
		cout << "\nEnter reference to subject Name";
		cin.sync();
		getline(cin, subject);
		cout << "\nEnter Number Of Copies";
		cin >> count;
		cout << "\n" << item3->setItem(name, author, subject, count);
		items.push_back(item3);
	}
			break;
	case 4:
	{
		return;
	}
			break;
	default:
	{
		cout << "\nInvalid Choice..!";
	}
			break;
	
	}
}
catch(exception &e){
	cout<<e.what();
}

}
