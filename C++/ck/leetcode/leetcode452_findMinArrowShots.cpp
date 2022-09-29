#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool myCompare(vector<int>& a, vector<int>& b) {
        return a[0] <= b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;

        //根据起始位置排序
        sort(points.begin(), points.end(), myCompare);
        int ans = 1;
        int minEnd = points[0][1];                      //记录重叠部分的最小右边界
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] <= minEnd) minEnd = min(minEnd, points[i][1]);
            else {
                ans++;
                minEnd = points[i][1];
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    int num = test.findMinArrowShots(points);
    return 1;
}