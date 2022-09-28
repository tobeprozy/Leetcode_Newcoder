#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A::construct function" << endl;
    }

    virtual void f() {
        cout << "A::f()" << endl;
    }

    void g() {
        cout << "A::g()" << endl;
    }

    virtual ~A() {
        cout << "A::destructor function" << endl;
    }
};

class B : public A{
public:
    B() {
        cout << "B::construct function" << endl;
    }

    virtual void f() {
        cout << "B::f()" << endl;
    }

    void g() {
        cout << "B::g()" << endl;
    }

    virtual ~B() {
        cout << "B::destructor function" << endl;
    }

};

int main() {
    A* obj1 = new B();
    B* obj2 = new B();
    obj1->f();
    obj1->g();
    obj1->A::f();
    obj1->A::g();
    // obj1->B::g(); 会报错

    obj2->f();
    obj2->g();
    obj2->A::f();
    obj2->A::g();
    obj2->B::g();  

    delete obj1;
    delete obj2;

    return 0;
}
