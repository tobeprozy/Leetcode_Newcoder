#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<int> one(n, 0);
    vector<int> two(m, 0);

    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        if (i == 0) one[i] = ai;
        else one[i] = ai + one[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int bi;
        cin >> bi;
        if (i == 0) two[i] = bi;
        else two[i] = bi + two[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (one[i] + two[j] <= t) ans = max(ans, i + j + 2);
        }
    }
    cout << ans << endl;
    return 0;
}