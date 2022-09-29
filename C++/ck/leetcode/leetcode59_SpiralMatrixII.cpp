#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int elem = 1;
        int count = 0;
        while (elem <= n * n) {
            for (int i = count; i < n - count; i++) {
                result[count][i] = elem;
                elem++;
            }
            for (int i = count + 1; i < n - count; i++) {
                result[i][n - count - 1] = elem;
                elem++;
            }
            for (int i = n - count - 2; i >= count; i--) {
                result[n - count - 1][i] = elem;
                elem++;
            }
            for (int i = n - count - 2; i > count; i--) {
                result[i][count] = elem;
                elem++;
            }
            count++;
        }
        return result;
    }
};

int main() {
    Solution test;
    test.generateMatrix(1);
    return 0;
}