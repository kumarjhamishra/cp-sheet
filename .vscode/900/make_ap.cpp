#include <bits/stdc++.h>
using namespace std;
// make_ap.cpp

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    // base case - already in ap
    if (b - a == c - b)
    {
        cout << "YES" << endl;
        return;
    }

    // check for a, b and c one by one
    int x;

    // check for value at the place of a
    x = b - (c - b);
    if (x >= a && x % a == 0 && x != 0)
    {
        cout << "YES" << endl;
        return;
    }

    // check for b
    x = a + (c - a) / 2;
    if ((c - a) % 2 == 0 && x >= b && x % b == 0 && x != 0)
    {
        cout << "YES" << endl;
        return;
    }

    // check for c
    x = a + 2 * (b - a);
    if (x >= c && x % c == 0 && x != 0)
    {
        cout << "YES" << endl;
        return;
    }



    cout << "NO" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}