#include<iostream>
using namespace std;

int main()
{
    int level = 15;
    int aestric = 1;
    for (int l = 1; l <= level; l++)
    {
        for (int i = level; i > l; i-- )
        {
            cout << " ";
        }
        for (int j = 1; j <= aestric; j++ )
        {
            cout << "*";
        }
        aestric += 2;
        cout << endl;
    }
}