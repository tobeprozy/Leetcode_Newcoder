#include "../bits/stdc++.h"

using namespace std;

int f(int n){
    cout<<n<<endl;
    return n;
}

void fun(int param1,int param2){
    int var1=param1;
    int var2=param2;

    printf("var1=%d,var2=%d",f(var1),f(var2));
}

int main(){

    fun(1,2);
    return 0;
}

// 当main函数开始调用fun()函数时，
// 编译器此时会将main函数的运行状态进行压栈，
// 再将fun()函数的返回地址、fun()函数的参数从右到左、fun()定义变量依次压栈；

// 当fun()调用f()的时候，编译器此时会将fun()函数的运行状态进行压栈，
// 再将的返回地址、f()函数的参数从右到左、f()定义变量依次压栈