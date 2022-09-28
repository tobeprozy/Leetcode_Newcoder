#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};

int main() {
    Solution test;
    int n = 2;
    int ans = test.integerBreak(n);
    return 0;
}