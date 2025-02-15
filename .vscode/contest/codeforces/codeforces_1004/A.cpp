#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x, y;
    cin >> x >> y;

    if (x + 1 - y < 0)
    {
        cout << "NO" << endl;
        return ;
    }
    if ((x + 1 - y) % 9 == 0)
    {
        cout << "YES" << endl;
        return ;
    }
    else
    {
        cout << "NO" << endl;
        return ;
    }

    if (y - x == 1)
    {
        cout << "YES" << endl;
        return ;
    }

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