#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int zhuanzhi(vector<vector<int>>& x) {
        int n = x.size();
        int ans = 0;
        vector<vector<int>> z(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                z[i][j] = x[j][i];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += abs(z[i][j] - x[i][j]);
            }
        } 
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> x(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x[i][j];
        }
    }

    Solution test;
    int value = test.zhuanzhi(x);
    cout << value << endl;
    return 0;
}