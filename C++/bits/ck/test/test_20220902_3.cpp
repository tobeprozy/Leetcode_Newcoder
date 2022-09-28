#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    long strtolong(string& str) {
        long ans = 0;
        long flag = 1;
        int n = str.size();
        for (int i = n - 1; i >= 0; i--) {
            ans += flag * (str[i] - '0');
            flag *= 10;
        }
        return ans;
    }

    string multiply(string& str1, string& str2) {
        long ji = strtolong(str1) * strtolong(str2);
        string ans;

        while (ji > 0) {
            char temp = '0' + (ji % 10);
            ans += temp;
            ji /= 10;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    Solution test;
    cout << test.multiply(str1, str2) << endl;

    return 0;
}