#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long minCost(long long a, long long b)
{
    while (b)
    {
        long long carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

void solve()
{
    long long x, y;
    cin >> x >> y;
    if (x == y)
    {
        cout << "0\n";
        return ;
    }
    long long a = 0, b = 0;
    long long xx = x, yy = y;
    while (xx != yy)
    {
        if (xx > yy)
        {
            xx >>= 1;
            a++;
        }
        else
        {
            yy >>= 1;
            b++;
        }
    }
    cout << minCost(a, b) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}