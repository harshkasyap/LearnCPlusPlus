#include <iostream>
using namespace std;

class Parent {
    public:
        int x;
};

class Oops : private Parent
{
    public:
        static int a;
        Oops();
        Oops(Oops &);
        void set(int _x);
        int print()
        {
            return x;
        }

        string operator+ (string);
        string reverse (string);
        friend void globalFunc(Oops&);
};

int Oops::a = 10;

void globalFunc(Oops& oops)
{
    cout << "Friend: " << oops.a << endl;
}

Oops :: Oops() {
    // Nothing to do
}

Oops :: Oops(Oops &oops) 
{
    x = oops.x;
}

void Oops :: set(int _x)
{   
    x = _x;
}

string Oops :: operator+ (string _x) 
{   
    return _x + to_string(x);   
}

string Oops :: reverse (string _x) 
{
    int flag=0;
    for (int i = 0; i < _x.length()/2; i++)
    {
        if (_x[i] != _x[_x.length()-i-1]) {
            cout << "Not a Palindrome" << endl;
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "It is a palindrome" << endl;
        return _x;
    }

    for (int i = 0; i < _x.length()/2; i++)
    {
        swap(_x[i], _x[_x.length()-i-1]);
    }
    return _x;
}

int main(int argc, char const *argv[])
{
    Oops oops, oops1;
    oops.set(10);
    globalFunc(oops);
    cout << oops.print() << endl;
    oops1 = oops;
    cout << oops1.print() << endl;
    char str [] = "test";
    string operOverString =  oops1 + str;
    char palindromeStr [] = "12121";
    string revOperOverStrig = oops1.reverse(palindromeStr);
    cout << revOperOverStrig;
    return 0;
}
