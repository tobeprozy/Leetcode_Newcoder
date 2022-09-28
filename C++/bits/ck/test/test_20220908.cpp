#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main() {
    int p;
    cin >> p;
    int q;
    cin >> q;

    vector<int> all(p, 0);   // 所有事业部
    for (int i = 0; i < p; i++) {
        int num;
        cin >> num;
        all[i] = num;
    }

    vector<int> sorted(q, 0);   // 重点关注事业部
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        sorted[i] = num;
    }

    unordered_map<int, int>  mp;
    for (int& num : all) mp[num]++;   // 可能重复提交

    unordered_set<int> st;
    for (int& num : sorted) st.insert(num);

    vector<int> rest;
    for (int& num : all) {
        if (st.find(num) == st.end()) rest.push_back(num);
    }

    sort(rest.begin(), rest.end());

    for (int& num : sorted) {
        for (int i = 0; i < mp[num]; i++) {
            cout << num;
            cout << ' ';
        }
    }

    for (int i = 0; i < rest.size(); i++) {
        if (i != rest.size() - 1) {
            cout << rest[i];
            cout << ' ';
        }else cout << rest[i];
    }

    return 0;
}