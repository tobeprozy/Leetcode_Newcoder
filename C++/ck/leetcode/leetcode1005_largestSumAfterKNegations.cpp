#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //对最小值取反（负数）
        sort(nums.begin(), nums.end());
        int sum = 0;              //记录和
        int minvalue = abs(nums[0]);   //记录当前数组最小值
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 && k > 0) {
                nums[i] = -1 * nums[i];
                k--;
            }
            sum += nums[i];
            minvalue = min(minvalue, nums[i]);
        }
        if (k % 2 == 1) sum = sum - 2*minvalue;
        return sum;
    }
};

int main() {
    Solution test;
    vector<int> matrix = {-4, -6, 9, -2, 2};
    int k = 4;
    int ans = test.largestSumAfterKNegations(matrix, k);
    return 0;
}