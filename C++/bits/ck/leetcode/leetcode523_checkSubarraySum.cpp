#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //前缀和
        unordered_map<int, int> preSumMp;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum % k == 0 && i != 0) return true;
            else {
                if (preSumMp.find(sum % k) != preSumMp.end() && i - preSumMp[sum % k] > 1) return true;
            }
            preSumMp[sum % k] = i;
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1,2,12};
    bool value = test.checkSubarraySum(nums, 6);
    return 0;
}