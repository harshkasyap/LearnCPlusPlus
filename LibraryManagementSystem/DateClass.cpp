#include "DateClass.h"
#include"NumberException.h"

string DateClass::setDate(int day,int month, int year){

	if(day<1){
		throw NumberException();
	}
	if(month<1){
		throw NumberException();
	}
	if(year<1){
		throw NumberException();
	}

	this->day=day;
	this->month=month;
	this->year=year;
	
	string msg="date added sucessfully!";
	return msg;

}

int DateClass::getDay(){
	return day;
}

int DateClass::getMonth(){
	return month;
}

int DateClass::getYear(){
	return year;
}

string DateClass::getDate(){

	string date="";
	ostringstream os;
	os << day;
	date.append(os.str()+"-");
	ostringstream os1;
	os1 << month;
	date.append(os1.str()+"-");
	ostringstream os2;
	os2 << year;
	date.append(os2.str());
	
	return date;

}

int DateClass::diffInDate(DateClass date){

	int d1=day,m1=month,y1=year,d2=date.getDay(),m2=date.getMonth(),y2=date.getYear(),diff=0;
	int noOfDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	if(y2>y1){
		if(y1%4==0)
			noOfDays[1]=29;
		else
			noOfDays[1]=28;
		
		int tM1=noOfDays[m1-1];
		diff+=(tM1-d1);
		while(++m1!=13){
			diff+=noOfDays[m1-1];
		}
		
		if(y2%4==0)
			noOfDays[1]=29;
		else
			noOfDays[1]=28;
		
		diff+=d2;
		m1=0;
		while(++m1!=m2){
			diff+=noOfDays[m1-1];
		}
		
		while(++y1!=y2){
			if(y1%4==0)
				diff+=366;
			else
				diff+=365;
		}
		return diff;
	}
	else{
		if(m2>m1){
			if(y1==y2){
			
				if(y1%4==0)
					noOfDays[1]=29;
				else
					noOfDays[1]=28;
					
				int tM1=noOfDays[m1-1];
				diff+=(tM1-d1);
				diff+=d2;
				while(++m1!=m2){
					diff+=noOfDays[m1-1];
				}
				return diff;
			}
			else{
				return -1;
			}
		}
		else{
			if(d2>d1){
				if(m1==m2){
					diff=d2-d1;
					return diff;
				}
				else{
					return -1;
				}
			}
			else{
				return -1;
			}
		}			
	}
		
}



