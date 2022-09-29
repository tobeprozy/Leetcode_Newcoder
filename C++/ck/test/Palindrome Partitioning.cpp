#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    void dfs(string& s, int index) {
        if (index >= s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            string temp = s.substr(index, i - index + 1);
            if (isPalindrome(temp)) {
                path.push_back(temp);
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }else return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    Solution test;
    vector<vector<string>> ans = test.partition(s);
    for (int i = 0; i < ans.size(); i++) {
        vector<string> temp = ans[i];
        for (string& str : temp) cout << str << endl;
    }
    return 0;
}