#include<iostream>
using namespace std;

int main()
{
    /// int random;
    char hello[] = "HelloWorld!";
    // cin >> random;
    cout << hello << endl;
    // cerr << "Error Occured?\n";
    // clog << "Error Occured?\n";

    /* Diff between getline and cin
    string str;
    int t = 4;
    while (t--)
    {
        // getline(cin, str);
        cin >> str;
        while (str.length()==0 )
            getline(cin, str);
        cout << str << " : newline" << endl;
    }*/

    /* boolean variable is always reassigned value 1 when incremented(for both true/false). and hence this will run infinite.
    bool a = true;
    for (a = 1; a <= 5; a++)
        cout << a;*/

    /* There is no index out of bound checking in C,C++ Still how it is not reporting any error in priting the value?
    int arr[2];
    arr[5] = 2;
    cout << arr[0] << endl;
    cout << arr[5] << endl;
    cout << arr[-2] << endl;
    cout << sizeof(arr)/sizeof(arr[0]) << endl;

    // can't exceed array size in initialization, can do in c though.
    // int arr1[2] = {10, 20, 30, 40, 50}; */

    
    // Declare an array
    int val[3] = { 5, 10, 20 };
 
    // Declare pointer variable
    int *ptr;
 
    // Assign address of val[0] to ptr.
    // We can use ptr=&val[0];(both are same)
    ptr = val ;
    cout << "Elements of the array are: ";
    // cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
    cout << *(val+1);
    
    //return 0;
}