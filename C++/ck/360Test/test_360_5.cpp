#include<iostream>
using namespace std;

class A{
public:
    void f() {
        cout << "A::f()" << endl;
    }
    virtual void g() {
        cout << "A::g()" << endl;
    }
};

class B: public A {
public:
    void f() {
        cout << "B::f()" << endl;
    }

    void g() {
        cout << "B::g()" <<endl;
    }
};

int main() {
    B b;
    A *pa = &b;
    if (dynamic_cast<B*>(pa) == NULL) {
        cout << "NULL" << endl;
    }else {
        dynamic_cast<B*>(pa)->f();   
        dynamic_cast<B*>(pa)->g();
    }
    return 0;
}
