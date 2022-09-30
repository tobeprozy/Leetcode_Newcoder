#include "../bits/stdc++.h"
//一定要用"",否则找不到

using namespace std;

struct Person{

    string name;
    int age;
    //初始化构造函数
    Person(string p_name,int p_age):name(move(p_name)),age(p_age)
    {
        cout<<"i have been constructed"<<endl;
    };

        //拷贝构造函数
     Person(const Person& other): name(move(other.name)), age(other.age)
    {
         cout << "I have been copy constructed" <<endl;
    }
     //转移构造函数
     Person(Person&& other): name(move(other.name)), age(other.age)
    {
         cout << "I have been moved"<<endl;
    }

};


int main(){

    vector<Person> e;
    cout<<"emplace_back:"<<endl;
    e.emplace_back("Jane",23);//不用构造函数

    vector<Person> p;
    cout<<"push_back:"<<endl;
    p.push_back(Person("Mike",36));//用构造函数
    return 0;
}