#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isTriangle(vector<int>& length) {
        sort(length.begin(), length.end());
        return length[0] + length[1] > length[2];
    }
};

int main() {
    vector<int> length(3, 0);
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        length[i] = n;
    }

    Solution test;
    bool ans = test.isTriangle(length);
    cout << boolalpha;
    cout << ans << endl;

    return 0;
}