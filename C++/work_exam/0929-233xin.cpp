#include <bits/stdc++.h>

using namespace std;

long long adddig(long long num)
{
    long long sum = 0;
    for (int i = 1; num > 0; i++)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;

}
int iseq(int x)
{
    int k = x / 233;
    return adddig(k);
}

int main()
{
    int n;
    cin >> n;
    int x;
    while (n--)
    {
        cin >> x;
        if (x % 233 != 0)
            cout << -1;
        cout << adddig(x) << endl;
    }
    return 0;
}