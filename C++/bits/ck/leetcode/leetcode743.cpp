#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra（迪杰斯特拉）

        // 节点0 ~ n - 1
        // 邻接矩阵
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX / 2));
        // 初始化
        for (int i = 0; i < n; i++) graph[i][i] = 0;
        // 创建图（有向图）
        for (int i = 0; i < times.size(); i++) {
            graph[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }

        vector<int> distance(n, INT_MAX / 2);    // 保存起始节点到各个节点的距离
        vector<bool> visited(n, false);      // 记录节点是否已经访问过
        distance[k - 1] = 0;                 // 记录起点距离为0

        for (int i = 0; i < n; i++) {
            int x = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (x == -1 || distance[j] < distance[x])) x = j;
            }

            visited[x] = true;

            // 基于节点x对其所有相邻节点进行距离更新
            for (int j = 0; j < n; j++) {
                // 更新distance[i]
                distance[j] = min(distance[j], distance[x] + graph[x][j]);
            }
        }

        int ans = 0;
        for (int& num : distance) ans = max(num, ans);

        return ans == INT_MAX / 2 ? -1 : ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    int n = 4;
    int k = 2;
    int num = test.networkDelayTime(times, n, k);
    return 0;
}