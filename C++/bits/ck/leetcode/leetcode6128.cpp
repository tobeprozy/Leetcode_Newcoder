#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int, int> ranks_mp;
        unordered_map<char, int> suits_mp;
        for (int i = 0; i < suits.size(); i++) {
            suits_mp[suits[i]]++;
        }
        int ranks_max = 0;
        for (int i = 0; i < ranks.size(); i++) {
            ranks_mp[ranks[i]]++;
            ranks_max = max(ranks_max, ranks_mp[ranks[i]]);
        }
        
        if (suits_mp.size() == 1) return "Flush";
        if (ranks_max >= 3) return "Three of a Kind";
        else if (ranks_max = 2) return "Pair";
        return "High Card";
    }
};

int main() {
    Solution test;
    vector<int> ranks = {13, 12, 3, 4, 7};
    vector<char> suits = {'a','d','c','b','c'};
    string result = test.bestHand(ranks, suits);
    return 0;
}