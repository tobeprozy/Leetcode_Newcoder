#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    int num;
    char *name;
public:
    Student() {
        name = new char(20);
        
    }
    ~Student() {
        delete name;
        name = NULL;
    };
};

int main() {

    Student stu1;

    return 0;

}