// alignas 生效的情况
#include <iostream>

using namespace std;
//智能对齐shift

int main()
{
    struct Info
    {
        uint8_t a;
        uint16_t b;
        uint8_t c;
    };

    std::cout << sizeof(Info) << std::endl;  // 6  2 + 2 + 2
    std::cout << alignof(Info) << std::endl; // 2

    struct alignas(4) Info2
    {
        uint8_t a;
        uint16_t b;
        uint8_t c;
    };

    std::cout << sizeof(Info2) << std::endl;  // 8  4 + 4
    std::cout << alignof(Info2) << std::endl; // 4
}
