#include<iostream>
using namespace std;
#include<string>

class Solution {
public:
    string replaceSpace(string s) {
        //先遍历一遍，找到字符串中有几个空格
        int left = s.size() - 1;              //左指针指向原字符串最后一个字符
        int spaceNum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') spaceNum++;
        }
        
        string spacestr(spaceNum * 2, ' ');
        s += spacestr;                        //扩展字符串s的容量
        int right = s.size() - 1;             //右指针指向扩展后字符串最后一个字符

        while (left >= 0) {
            if (s[left] != ' ') s[right--] = s[left--];
            else {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
                left--;
            }
        }
        return s;
    }
};

int main() {
    Solution test;
    string str1("We are happy.");
    string str2 = test.replaceSpace(str1);
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}