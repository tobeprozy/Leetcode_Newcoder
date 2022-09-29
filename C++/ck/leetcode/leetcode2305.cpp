#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& cookies, vector<int>& bag, int k, int& ans, int index) {
        //饼干发完了
        if (index == cookies.size()) {
            //遍历bag找到孩子获得的最大饼干总数
            int temp = 0;
            for (int& num : bag) temp = max(temp, num);
            //更新ans
            ans = min(temp, ans);
            return;
        }

        for (int i = 0; i < k; i++) {
            //回溯
            bag[i] += cookies[index];
            backtracking(cookies, bag, k, ans, index + 1);
            bag[i] -= cookies[index];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        //将cookies从大到小排序
        //在回溯过程中，先发饼干较多的零食包
        sort(cookies.begin(), cookies.end(), greater<int>());
        int ans = INT_MAX;
        vector<int> bag(k, 0);   //用于回溯过程中放置孩子被分发到的饼干

        //开始回溯
        backtracking(cookies, bag, k, ans, 0);
        return ans;
    }
};

int main() {
    vector<int> cookies = {8,15,10,20,8};
    int k = 2;
    Solution test;
    int ans = test.distributeCookies(cookies, k);
    return 0;
}