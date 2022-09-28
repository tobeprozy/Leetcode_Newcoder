#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求取指定长度序列的和
     * @param n int整型 序列长度
     * @return float浮点型
     */
    float seqSum(int n) {
        // write code here
        float sum = 0;
        float fenzi = 1.0;
        float fenmu = 2.0;
        for (int i = 0; i < n; i++) {
            sum += fenzi / fenmu;
            float temp = fenmu;
            fenmu += fenzi;
            fenzi = temp;
        }
        int cur = (int) (sum * 1000);
        if (cur % 10 >= 5) cur += 10;
        cur /= 10;
        return (float) cur / 100;
    }
};

int main() {
    Solution test;
    int n = 1;
    float ans = test.seqSum(n);
    return 0;
}
