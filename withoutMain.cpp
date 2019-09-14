#include <iostream>
using namespace std;

extern void _exit(register int);

int _start() {
    cout << "Hello World";

    _exit(0);
}