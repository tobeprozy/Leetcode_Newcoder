#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //二分查找
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            //判断[left,mid],[mid+1,right]哪个区间有序
            if (nums[left] <= nums[mid]) {
                if (nums[mid] > target && nums[left] <= target) right = mid - 1;    //判断target是否落在有序区间内
                else left = mid + 1;
            }else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }   
        return -1; 
    }
};

int main() {
    Solution test;
    vector<int> nums = {3, 1};
    int target = 1;
    int result = test.search(nums, target);
    return 0;
}