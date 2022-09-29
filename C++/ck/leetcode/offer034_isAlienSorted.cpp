#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //根据字母表的顺序重新定义字母排序
        vector<int> reorder(27, 0);
        for (int i = 1; i < 27; i++) reorder[order[i - 1] - 'a' + 1] = i;

        //依次比较单词
        for (int i = 0; i < words.size() - 1; i++) {
            int index1 = 0;
            int index2 = 0;
            while (index1 < words[i].size() || index2 < words[i + 1].size()) {
                int x = index1 < words[i].size() ? words[i][index1] - 'a' + 1 : 0;
                int y = index2 < words[i + 1].size() ? words[i + 1][index2] - 'a' + 1 : 0;
                if (reorder[x] < reorder[y]) break;
                else if (reorder[x] > reorder[y]) return false;
                index1++;
                index2++;
            }
        }
        return true;
    }
};

int main() {
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution test;
    bool ans = test.isAlienSorted(words, order);
    return 0;
}