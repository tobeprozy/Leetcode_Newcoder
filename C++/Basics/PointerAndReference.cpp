#include <iostream>
#include "../bits/stdc++.h"

using namespace std;

class Student
{
private:
    int num;
    char *name;
public:
    Student(){
        name=new char(20);
        cout<<"Student"<<endl;
        
        memcpy(name,"abcdrfg",strlen("abcdrfg"));
        //name="abcdrfg";
        cout<<*name<<endl;
        cout<<*(name+1)<<endl;
        cout<<*name+1<<endl;
        cout<<"name address:"<<&name<<endl;
        //name++;
        cout<<*name<<endl;
        cout<<"name+1 address:"<<&name<<endl;
    }
    ~Student(){
        cout<<"&name:"<<&name<<endl;
        delete name;
        name==nullptr;
    };
};

int main(){

    Student stu1;
    //测试指针和引用++的区别
    int a[2]={0,1};
    //int &b=a;
    int *p=a;
    cout<<"a:"<<a<<endl;
    cout<<"a+1:"<<a+1<<endl;

    // cout<<"&(a+1):"<<&(a+1)<<endl;//错误

    cout<<"&a:"<<&a<<endl;
    cout<<"&a+1:"<<&a+1<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"p+1:"<<p+1<<endl;

    cout<<"sizeof(&a):"<<sizeof(&a)<<endl;
    cout<<"sizeof(p):"<<sizeof(p)<<endl;

    cout<<"*p:"<<*p<<endl;
    cout<<"*p+10:"<<*p+10<<endl;
    cout<<"*(p+1):"<<*(p+1)<<endl;
    
}