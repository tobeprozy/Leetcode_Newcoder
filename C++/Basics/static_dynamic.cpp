#include "../bits/stdc++.h"

using namespace std;

class A{
    public:
    virtual void func(){cout<<"A::func()\n";}


};

class B:public A{
    public:
        void func(){cout<<"B::func()\n";}
};

class C:public A{
    public:
    void func(){cout<<"C::func()\n";}
};

int main(){

    C* pc=new C();//pc的静态类型是它声明的类型C*，动态类型也是C*；
    B* pb=new B();//pb的静态类型和动态类型也都是B*；
    A* pa=pc;//pa的静态类型是它声明的类型A*，动态类型是pa所指向的对象pc的类型C*；

    pa=pb; //pa的动态类型可以更改，现在它的动态类型是B*，但其静态类型仍是声明时候的A*；
    C *pnull = NULL; //pnull的静态类型是它声明的类型C*,没有动态类型，因为它指向了NULL；

    // pa->func();//A::func() pa的静态类型永远都是A*，不管其指向的是哪个子类，都是直接调用A::func()；
    // pc->func();      //C::func() pc的动、静态类型都是C*，因此调用C::func()；
    // pnull->func();   //C::func() 不用奇怪为什么空指针也可以调用函数，因为这在编译期就确定了，和指针空不空没关系；

    //如果基类是虚函数
    pa->func();      //B::func() 因为有了virtual虚函数特性，pa的动态类型指向B*，因此先在B中查找，找到后直接调用；
    pc->func();      //C::func() pc的动、静态类型都是C*，因此也是先在C中查找；
    pnull->func();   //空指针异常，因为是func是virtual函数，因此对func的调用只能等到运行期才能确定，然后才发现pnull是空指针；
 
    return 0;
}


// 如果基类A中的func不是virtual函数，那么不论pa、pb、pc指向哪个子类对象，
// 对func的调用都是在定义pa、pb、pc时的静态类型决定，早已在编译期确定了。

// 如果func是虚函数，那所有的调用都要等到运行时根据其指向对象的类型才能确定，
// 比起静态绑定自然是要有性能损失的，但是却能实现多态特性；

// 在继承体系中只有虚函数使用的是动态绑定，其他的全部是静态绑定；
