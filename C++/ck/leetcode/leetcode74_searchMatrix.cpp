#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //两次二分查找
        //先确定在哪一行
        int left = 0;
        int right = matrix.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                right = mid;
                left = mid + 1;
            }
            else if (matrix[mid][0] > target) right = mid - 1;
            else left = mid + 1;
        }
        //再确定哪一列
        int row = 0;
        if (left == 0) row = left;
        else row = left -1;
        
        left = 0;
        right = matrix[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<vector<int>> matrix = {{1}};
    int target = 0;
    bool flag = test.searchMatrix(matrix, target);
    return 0;
}