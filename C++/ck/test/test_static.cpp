#include<iostream>
using namespace std;

void add1() {
    static int a = 0;
    a++;
    cout << a << endl;
}

void add2() {
    static int a;
    a++;
    cout << a << endl;
}

int main() {
    add1();
    add1();
    add2();
    add2();
    return 0;
}
