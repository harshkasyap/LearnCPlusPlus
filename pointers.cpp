/******************************************************************************
                                 Pointers.
*******************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

int
main ()
{
  cout << "------" << endl;
  char *s = "Test String";
  cout << "s: " << s << endl;
  cout << "*s: " << *s << endl;
  cout << "&s: " << &s << endl;

  int x = 5;
  int *p = &x;

  cout << "p: " << p << endl;
  cout << "*p: " << *p << endl;
  cout << "&p: " << &p << endl;

  char str = 's';
  char *pstr = &str;

  cout << "pstr: " << pstr << endl;
  cout << "*pstr: " << *pstr << endl;
  cout << "&pstr: " << &pstr << endl;

  int arr[]= {1, 2, 3, 4};
  cout << "arr: " << arr << endl;
  cout << "*arr: " << *arr << endl;
  cout << "&arr: " << &arr << endl;

  int *parr = &arr[1];
  // it also works
  // int *parr = arr + 2;
  cout << "parr: " << parr << endl;
  cout << "*parr: " << *parr << endl;
  cout << "&parr: " << &parr << endl;

  char * mstr= "Sub String Test";
  cout << "mstr: " << mstr + 4<< endl;
  cout << "*mstr: " << *mstr << endl;
  cout << "&mstr: " << &mstr << endl;

  char *msstr = (char *)malloc(6 * sizeof(char));
  memcpy(msstr, mstr + 4, 6);
  // it also works
  // memcpy(msstr, &mstr[4], 6);
  cout << "msstr: " << msstr << endl;
  cout << "*msstr: " << *msstr << endl;
  cout << "&msstr: " << &msstr << endl;

  return 0;
}