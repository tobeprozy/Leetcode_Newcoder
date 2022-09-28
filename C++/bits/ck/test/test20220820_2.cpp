#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 验证指令的正确性
     * @param signal string字符串 待验证的指令
     * @return bool布尔型
     */
    bool signalVerify(string signal) {
        // write code here
        if (!islower(signal[0])) return false;
        if (signal[2] == ' ') return false;
        for (int i = 2; i < signal.size(); i++) {
            if (!islower(signal[i]) || !isdigit(signal[i])) return false;
        }
        return true;
    }
};

int main() {
    Solution test;
    string signal = "v=0";
    bool ans = test.signalVerify(signal);
    return 0;
}