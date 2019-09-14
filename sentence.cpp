#include<iostream>
using namespace std;

string reverse(string str)
{
    int size = str.size();
    for(int i = 0; i < (size/2); i++)
    {
        swap(str[i], str[size-i-1]);
    }
    return str;
}

int main()
{
    int n, i;
    string strB;
    cout<<"Enter the number to convert: ";    
    cin>>n;    
    for(i=0; n>0; i++)    
    {    
        strB += to_string(n%2);  
        n = n/2;  
    }

    cout<<"Binary"<<strB<<endl;  

    string str = "Welcome to the computer world.";
    string strWords[5];
    short counter = 0;
    for(short i=0;i<str.length();i++){
        strWords[counter] += str[i];
        if(str[i] == ' '){
            cout << reverse(strWords[counter]) << endl;
            counter++;
        }
    }
}