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
    };
    ~Student(){
        cout<<"~Student:"<<&name<<endl;
        //delete name;
        //name=nullptr;
    };

    Student(const Student &s){
        //浅拷贝，对象的name和传入对象s的name具有相同的地址
        name=s.name;
        //深拷贝
        // name=new char(20);
        // memcpy(name,s.name,strlen(s.name));
        cout<<"copy student"<<endl;
    };

};


int main(){

    Student stu1;
    Student stu2(stu1);

    system("pause");
    return 0; 
    
}