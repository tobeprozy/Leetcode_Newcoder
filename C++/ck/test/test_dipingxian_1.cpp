#include<iostream>
#include<functional>

int a = 10;

std::function<void()> GetFunc() {
    int a = 20;
    auto func = [&a]() {
        std::cout << a << std::endl;
    };
    return func;
}

int main() {
    a++;
    GetFunc()();
    return 0;
}
