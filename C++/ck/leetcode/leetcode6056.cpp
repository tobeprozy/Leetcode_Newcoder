#include<iostream>
using namespace std;
#include<string>

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        string temp = "";
        for (int i = 0; i < num.size() - 3; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                temp = num.substr(i, 3);
                if (ans == "") ans = temp;
                else ans = ans - "000" > temp - "000" ? ans : temp;
            }
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    string num = "6777133339";
    string ans = mySolution.largestGoodInteger(num);
    return 0;
}