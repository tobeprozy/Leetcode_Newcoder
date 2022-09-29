#include<iostream>
#include<vector>
using namespace std;


class Point{
public:
    int x;
    int y;
    Point(int xx, int yy) : x(xx), y(yy) {}
};

/**
 * struct Point {
 *	int x;
 *	int y;
 *	Point(int xx, int yy) : x(xx), y(yy) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param maze int整型vector<vector<>> 迷宫数据 固定为4x4的二维数组，0表示路，可走；1 表示墙，不可通过； 8 表示礼物，是我们的目标
     * @return Point类vector
     */

    vector<Point> path;
    vector<vector<Point>> all;
    int n;
    
    void dfs(vector<vector<int>>& visited, int x, int y ) {
        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] == 1) return;
        if (visited[x][y] == 8) {
            all.push_back(path);
            return;
        }
        path.push_back(Point(x, y));
        visited[x][y] = 1;
        dfs(visited, x + 1, y);
        dfs(visited, x - 1, y);
        dfs(visited, x, y - 1);
        dfs(visited, x, y + 1);
    }   
    
    vector<Point> winMazeGift(vector<vector<int>>& maze) {
        // write code here
        // 先找到入口
        n = maze.size();
        vector<Point> p;
        for (int i = 0; i < n; i++) {
            if (maze[0][i] == 0) p.push_back(Point(0, i));
            if (maze[n - 1][i] == 0) p.push_back(Point(n - 1, i));
            if (i != 0 && i != n - 1 && maze[i][0] == 0) p.push_back(Point(i, 0));
            if (i != 0 && i != n - 1 && maze[i][n - 1] == 0) p.push_back(Point(i, n - 1));
        }
        
        vector<vector<int>> visited = maze;
        for (int i = 0; i < p.size(); i++) {
            visited = maze;
            dfs(visited, p[i].x, p[i].y);
        }
        
        vector<Point> ans;
        ans = all[0];
        for (int i = 0; i < all.size(); i++) {
            if (all[i].size() < ans.size()) ans = all[i];
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> maze = {{0,1,1,1},{0,0,0,1},{1,0,8,1},{1,0,1,1}};
    vector<Point> ans = test.winMazeGift(maze);
    return 0;
}