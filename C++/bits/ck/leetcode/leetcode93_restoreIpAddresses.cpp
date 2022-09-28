#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
public:
    vector<string> ans;
    string path;
    void dfs(string& s, int index, int num) {
        //已经完成一组分割
        if (num == 3) {
            string cur = s.substr(index, s.size() - index + 1);
            if (isValid(cur)) {
                path += cur;
                ans.push_back(path);
                path.erase(path.end() - cur.size(), path.end());
            }
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string temp = s.substr(index, i - index + 1);
            if (isValid(temp)) {
                path += temp;
                path += ".";
                num++;
                dfs(s, i + 1, num);
                path.erase(path.end() - 1, path.end());
                path.erase(path.end() - temp.size(), path.end());
                num--;
            }
        }
    }

    bool isValid(const string& s) {
        if (s.size() >= 4 || s.size() == 0) return false;
        if (s.size() == 3) {
            if (s[0] == '0') return false;
            if ((s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0' > 255) return false;
        }
        if (s.size() == 2) {
            if (s[0] == '0') return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0);
        return ans;
    }
};

int main() {
    Solution mySolution;
    string s = "25525511135";
    vector<string> ans = mySolution.restoreIpAddresses(s);
    return 0;
}