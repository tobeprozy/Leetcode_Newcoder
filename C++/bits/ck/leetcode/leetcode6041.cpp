#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>


class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (nums_map.find(nums[i][j]) == nums_map.end()) nums_map[nums[i][j]] = 1;
                else nums_map[nums[i][j]]++;
            }
        }
        vector<int> ans;
        for (auto it = nums_map.begin(); it != nums_map.end(); it++) {
            if (it->second == nums.size()) ans.push_back(it->first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> matrix = {{3,1,2,4,5}, {1,2,3,4}, {3,4,5,6}};
    vector<int> ans = test.intersection(matrix);
    return 0;
}