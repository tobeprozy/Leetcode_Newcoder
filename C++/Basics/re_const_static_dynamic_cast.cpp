#include "../bits/stdc++.h"
//一定要用"",否则找不到

using namespace std;

class Base
{
public:
    int b;
    Base() : b(1){};
    virtual void fun(){};
};

class Son : public Base
{
public:
    int d;
    Son() : d(2){};
};

int main()
{
    int n = 97;
    // reinterpret_cast
    {
        int *p = &n;
        //以下两者效果相同
        char *c = reinterpret_cast<char *>(p);
        cout << "reinterpret_cast输出：" << *c << endl;
        char *c2 = (char *)(p);
        cout << "reinterpret_cast输出：" << *c2 << endl;
    }
    // const_cast
    {
        const int *p2 = &n;              // p2指向的值是不能变的
        int *p3 = const_cast<int *>(p2); // p3指向的值可以变了；
        //*p2=100;//错误！
        *p3 = 100;
        cout << "const_cast输出：" << *p2 << endl;
        cout << "const_cast输出：" << *p3 << endl;
    }


    Base *b1 = new Son;  //子类
    Base *b2 = new Base; //父类
    {
        // static_cast
        Son* s1=static_cast<Son*> (b1);//同类转化
        Son* s2=static_cast<Son*> (b2);//下行转化
        cout << "static_cast输出：" << s1->d << endl;
        cout << "static_cast输出：" << s2->d << endl;//下行转换，原先父对象没有d成员，输出垃圾值

        //dynamic_cast
	    Son* s3 = dynamic_cast<Son*>(b1); //同类型转换
	    Son* s4 = dynamic_cast<Son*>(b2); //下行转换，安全
        cout << "dynamic_cast输出：" <<s3->d<< endl;
        if(s4==nullptr) cout << "s4 is nullptr" << endl;
        else cout << "dynamic_cast输出：" <<s4->d<< endl;
    }

    // reinterpret_cast输出：a
    // reinterpret_cast输出：a
    // const_cast输出：100
    // const_cast输出：100
    // static_cast输出：2
    // static_cast输出：-1163005939
    // dynamic_cast输出：2
    // s4 is nullptr
}
