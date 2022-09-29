#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string fanzhuan(string src) {
        int n = src.size();
        int lastpos = 0;
        int curpos = n - 1;
        // 去掉字符串前面和后面的空格
        while (src[lastpos] == ' ') lastpos++;
        while (src[curpos] == ' ') curpos--;
        string srccopy = src.substr(lastpos, curpos - lastpos + 1);

        n = srccopy.size();
        lastpos = 0;
        curpos = 0;
        vector<string> strs;
        while (curpos < n) {
            while (curpos < n && srccopy[curpos] != ' ') curpos++;
            string temp = srccopy.substr(lastpos, curpos - lastpos);
            strs.push_back(temp);
            while (curpos < n && srccopy[curpos] == ' ') curpos++;
            lastpos = curpos;
        }

        string ans;
        for (int i = strs.size() - 1; i >= 0; i--) {
            ans += strs[i];
            if (i != 0) ans += ' ';
        }
        return ans;
    }
};

int main() {

    Solution test;
    string src = " the sky is gray ";
    string value = test.fanzhuan(src);
    cout << value << endl;
    return 0;
}