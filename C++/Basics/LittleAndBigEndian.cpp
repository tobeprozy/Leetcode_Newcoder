#include <iostream>
#include "../bits/stdc++.h"

using namespace std;

union endian{
    int a;
    char ch;
};

int main(){

    int num=0x1234;
    char ch=(char)num;


    if(ch==0x34){//低地址是低位34 12
        cout<<"little endian"<<endl;
    }else if(ch==0x12){//低地址高位数  12 34
        cout<<"big endian"<<endl;
    }


    //method 2:
    endian value;
    value.a=0x1234;
    //a和ch共用4字节的内存空间
    
    if(value.ch==0x34){
        cout<<"little endian"<<endl;
    }else if(value.ch==0x34){
        cout<<"big endian"<<endl;
    }
}

