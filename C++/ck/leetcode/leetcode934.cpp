#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    queue<vector<int>> linkedQue;

    //深度优先搜索
    //将遍历到的单元格设置为2
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2) return;
        if (grid[i][j] == 0) {
            grid[i][j] = 2;
            linkedQue.push({i, j});
            return;
        }
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            dfs(grid, m, n, i - 1, j);
            dfs(grid, m, n, i + 1, j);
            dfs(grid, m, n, i, j - 1);
            dfs(grid, m, n, i, j + 1);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        //先找到一座岛，进行深度优先搜索
        //收集第一座岛周围的0
        //再进行广度优先搜索
        int m = grid.size();
        int n = grid[0].size();
        bool isfind = false;
        for (int i = 0; i < m; i++) {
            if (isfind == true) break;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, m, n, i, j);
                    isfind = true;
                    break;
                }
            }
        }

        //广度优先搜索第二座岛
        int ans = 0;
        while (!linkedQue.empty()) {
            int size = linkedQue.size();
            ans++;
            for (int i = 0; i < size; i++) {
                vector<int> temp = linkedQue.front();
                linkedQue.pop();
                for (int j = 0; j < 4; j++) {
                    int x = temp[0] + dx[j];
                    int y = temp[1] + dy[j];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[x][y] == 2) continue;
                        else if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            linkedQue.push({x, y});
                        }else if (grid[x][y] == 1) return ans;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> grid = {{0,1,0,0,0}, {0,1,0,1,1}, {0,0,0,0,1}, {0,0,0,0,0}, {0,0,0,0,0}};
    int result = test.shortestBridge(grid);
    return 0;
}