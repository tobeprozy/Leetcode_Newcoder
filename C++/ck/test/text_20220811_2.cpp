#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int myfun(int& n) {
        int flag = 1;
        while (!(n & 1)) {
            n >>= 1;
            flag *= 2;
        }
        return flag;
    }
};

int main() {
    int t;
    cin >> t;
    vector<int> nums(t, 0);
    for (int i = 0; i < t; i++) {
        cin >> nums[i];
    }

    Solution test;
    int ans = 0;
    for (int i = 0; i < t; i++) {
        ans = test.myfun(nums[i]);
        cout << ans << endl;
    }

    return 0;
}