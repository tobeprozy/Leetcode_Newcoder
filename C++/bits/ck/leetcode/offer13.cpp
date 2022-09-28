#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    int twosum(const int i, const int j) {
        int x = i;
        int y = j;
        int sum = 0;
        while (x > 0 || y > 0) {
            sum += (x % 10) + (y % 10);
            x /= 10;
            y /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        // 广度优先搜索
        queue<vector<int>> que;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        que.push({0, 0});
        visited[0][0] = true;
        int ans = 1;   // 第一个方格也要算上
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                vector<int> temp = que.front();
                que.pop();
                // visited[temp[0]][temp[1]] = true;
                for (int j = 0; j < 4; j++) {
                    int x = temp[0] + dx[j];
                    int y = temp[1] + dy[j];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                        if (twosum(x, y) <= k) {
                            que.push({x, y});
                            visited[x][y] = true;
                            ans++;
                        }
                    }
                }
            }

        }
        return ans;
    }
};

int main() {
    int m = 3;
    int n = 2;
    int k = 17; 
    Solution test;
    int ans = test.movingCount(m, n, k);
    return 0;
}