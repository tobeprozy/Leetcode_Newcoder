#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        if (nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        //定义left、right指针
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    path.push_back(nums[i]);
                    path.push_back(nums[left]);
                    path.push_back(nums[right]);
                    result.push_back(path);
                    path.clear();
                    while (right > left && nums[left + 1] == nums[left]) left++;
                    while (right > left && nums[right - 1] == nums[right]) right--;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans;
    Solution test;
    ans = test.threeSum(nums);
    return 0;
}