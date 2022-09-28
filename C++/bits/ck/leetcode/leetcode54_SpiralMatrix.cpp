#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int length = matrix[0].size();
        int width = matrix.size();
        vector<int> reslut(length * width);
        int count = 0;
        int time = 0;
        while (time < length * width) {
            for (int i = count; i < length - count; i++) {
                if (time >= length * width) break;
                reslut[time] = matrix[count][i];
                time++;
            }
            for (int i = count + 1; i < width - count; i++) {
                if (time >= length * width) break;
                reslut[time] = matrix[i][length - count - 1];
                time++;
            }
            for (int i = length - count - 2; i >= count; i--) {
                if (time >= length * width) break;
                reslut[time] = matrix[width - count - 1][i];
                time++;
            }
            for (int i = width - count - 2; i > count; i--) {
                if (time >= length * width) break;
                reslut[time] = matrix[i][count];
                time++;
            }
            count++;
        }
        return reslut;
    }
};

int main() {
    Solution test;
    vector<vector<int>> maxtrix {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> ans = test.spiralOrder(maxtrix);
    cout << "finished!" << endl;
    return 0;
}