#include<iostream>
using namespace std;
#include<vector>

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (int n, int k, int index) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = index; i <= n; i++) {
            path.push_back(i);             //处理节点
            backtracking(n, k, i + 1);     //递归
            path.pop_back();               //回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    Solution mySolution;
    mySolution.combine(4, 2);
    return 0;
}