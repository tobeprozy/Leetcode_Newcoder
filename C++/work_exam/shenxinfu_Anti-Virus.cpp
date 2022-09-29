#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> zj(n, 0);
    vector<int> upper(n, 0);
    vector<int> down(n, 0);
    for (int j = 0; j < n; j++)
    {
        int num;
        cin >> num;
        zj[j] = num;
        upper[j] = num + x;
        down[j] = num - x;
        if (down[j] < 0)
            down[j] = 0;
    }
    int ans = 0;

    int wupper = upper[0];
    int wdown = down[0];
    for (int j = 1; j < n; j++)
    {
        if (upper[j] < wdown || down[j] > wupper)
        {
            ann++;
            wupper = upper[j];
            wdown = down[j];
        }
        else
        {
            wupper = min(wupper, upper[j]);
            wdown = max(wdown, down[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
