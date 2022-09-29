#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        //连续元素序列用前缀和
        //子数组（非连续）组合或排列用回溯
        int right = 0;
        long long sum = nums[right];
        long long ans = 0;
        for (int left = 0; left < nums.size(); left++) {
            while (right < nums.size() && sum * (right - left + 1) < k) {
                right++;
                if (right < nums.size()) sum += nums[right];
            }
            ans += right - left;
            sum -= nums[left];
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2,1,4,3,5};
    long long k = 10;
    Solution test;
    long long ans = test.countSubarrays(nums, k);
    return 0;
}