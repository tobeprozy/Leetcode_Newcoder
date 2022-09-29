/*
01背包问题
背包最大重量为4；
物品为：
物品0：重量1，价值15；
物品1：重量3，价值20；
物品2：重量4，价值30。
*/

#include<iostream>
#include<vector>
using namespace std;

void test_2_wei_bag_problem1();
void test_1_wei_bag_problem();

int main() {
    test_1_wei_bag_problem();
    return 0;
}

void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    //定义二维数组，并初始化为0
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    //初始化dp[0][j]
    for (int j = weight[0]; j <= bagweight; j++) {
        //容量大于value[0]初始化为value[0]，否则为0
        dp[0][j] = value[0];
    }

    //先遍历物品，再遍历背包容量
    for (int i = 1; i < weight.size() - 1; i++) {
        for (int j = 0; j <= bagweight; j++) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
}

void test_1_wei_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    //定义一维数组，并初始化为0
    vector<int> dp(bagweight + 1, 0);
    //遍历物品，再倒序遍历背包容量
    for (int i = 0; i < weight.size(); i++) {
        for (int j = bagweight; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
}



