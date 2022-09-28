#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //两次二分法
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;

        //先找左边界
        int leftIndex = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else {
                if ((mid > 0 && nums[mid - 1] < target) || mid == 0) {
                    left = mid;
                    break;
                }else right = mid - 1;
            }
        }
        leftIndex = left;

        //再找右边界
        int rightIndex = 0;
        left = leftIndex;
        right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                if ((mid > 0 && nums[mid - 1] <= target) || mid == 0) {
                    left = mid;
                    break;
                }else right = mid;
            }
            else if (nums[mid] <= target) left = mid + 1;
        }
        rightIndex = left;

        return rightIndex - leftIndex;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 1;
    Solution test;
    int ans = test.search(nums, target);
    return 0;
}