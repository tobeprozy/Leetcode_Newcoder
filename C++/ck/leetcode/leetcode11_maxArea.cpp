#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        //双指针
        int left = 0;
        int right = height.size() - 1;
        int maxValue = 0;
        while (left < right) {
            maxValue = maxValue > min(height[left], height[right]) * (right - left) ? maxValue : min(height[left], height[right]) * (right - left);
            if (height[left] >= height[right]) right--;
            else left++;
        }
        return maxValue;
    }
};

int main() {
    Solution test;
    vector<int> height = {4,4,2,11,0,11,5,11,13,8};
    int value = test.maxArea(height);
    return 0;
}