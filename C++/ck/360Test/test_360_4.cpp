#include<iostream>
using namespace std;

class A {
    int i, j;

public:
    A(int x = 0, int y = 1) : i(x), j(y) {}
    void f() {
        cout << i + j;
    }
};

class B: public A {
    double a, b;

public:
    B(int x, int y, int z, int k): A(x, y), a(z), b(k) {}
    void f() {
        cout << a * b;
    }

};

int main() {
    B b(1, 2, 3, 4);
    B &rB = b;
    rB.f();
    A &rA = static_cast<A &>(b);
    rA.f();
    return 0;
}
