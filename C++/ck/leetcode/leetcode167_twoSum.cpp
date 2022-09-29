#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //双指针
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ans(2, 0);
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            }
            if (numbers[left] + numbers[right] < target) left++;
            else right--;
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = test.twoSum(numbers, target);
    return 0;
}
