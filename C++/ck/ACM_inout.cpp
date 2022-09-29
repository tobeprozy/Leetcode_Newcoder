#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    // 未规定输入数据的行数，但是规定了一行数据的个数未3个

    int a, b, c;
    vector<int> path(3, 0);
    vector<vector<int>> nums;
    while (cin >> a >> b >> c) {
        path[0] = a;
        path[1] = b;
        path[2] = c;
        nums.push_back(path);
    }

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << nums[i][j];
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}