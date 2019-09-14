#include "Library.h"

int main(){

	int ch;

	Library library;
	
	while(1){	
		
		cout<<"\nWelcome To Library Management Sytstem Portal";
		cout<<"\n1.Item \t2.Memeber \t0.Exit";
		
		cin>>ch;
		
		switch(ch){
		
		case 1:
			cout<<"\nHey..!Items Here!! ";
			cout<<"\nSelect 1.Add a new item 2.Display Items 3.Issue Items 4.Return Items";
			cin>>ch;
			switch(ch){
			
				case 1 :
					library.addItem();
					break;				
				case 2 :
					library.displayItems();
					break;
				case 3 :
					library.issueItem();
					break;								
				case 4 :
					library.returnItem();
					break;				
				default:
					cout<<"\nInvalid Choice..!";
					break;				
			}
			break;

		case 2:
			cout<<"\nHey..!Members Here!! ";
			cout<<"\nSelect 1.Add a new Member 2.Display All Members 3.Renew Membership 4.Close Membership ";
			cin>>ch;
			switch(ch){
			
				case 1 :
					library.addMember();
					break;				
				case 2 :
					library.displayMembers();
					break;
				case 3 :
					library.renewMember();
					break;				
				case 4 :
					library.closeMember();
					break;								
				default:
					cout<<"\nInvalid Choice..!";
					break;				
			}		
			break;
			
		case 0:
			exit(0);
			break;	
		
		default:
			cout << "Invalid Choice";
			break;
		}
	
	}
	
}
