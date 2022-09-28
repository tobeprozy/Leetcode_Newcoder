#include<iostream>
using namespace std;
class B {
public:
    ~B() {
        cout << "*";
    }
};

class D: public B {
public:
    D() {
        p = new int(0);
    }
    ~D() {
        cout << "#";
        delete p;
    }
private:
    int *p;
};

class C: public D {
public:
    C() {
        q = new int(0);
    }
    ~C() {
        cout << "#";
        delete q;
    }
private:
    int *q;
};

int main() {
    B *b1 = new D();
    delete b1;
    B *b2 = new C();
    delete b2;
    return 0;
}
