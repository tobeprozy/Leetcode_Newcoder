#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        //将n转换为数组，则与31.下一个排列相同
        vector<int> nums;
        while (n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());

        //与31.下一个排列相同
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i >= 0) {
            int j = nums.size() - 1;
            for ( ; j > i; j--) {
                if (nums[j] > nums[i]) break;
            }
            swap(nums[i], nums[j]);
        }else return -1;
        reverse(nums.begin() + i + 1, nums.end());

        long num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num *= 10;
            num += nums[i];
        }
        return num > INT_MAX ? -1 : num;
    }
};

int main() {
    Solution test;
    int n = 12;
    int num = test.nextGreaterElement(n);
    return 0;
}