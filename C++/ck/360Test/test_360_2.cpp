#include<iostream>
using namespace std;
class A {
public:
    void f() {
        cout << "*";
    }
    void g() {
        cout << "#";
    }
};

class B: public A{
public:
    void f() {
        cout << "&";
    }
    void g() {
        cout << "%";
    }
};

int main() {
    B b;
    A *pa = &b;
    reinterpret_cast<B*>(pa)->f();
    reinterpret_cast<B*>(pa)->g();
    return 0;
}
