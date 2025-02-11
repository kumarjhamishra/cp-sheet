#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        int prev = (i == 0 ? INT_MIN : a[i - 1]);

        if (a[i] >= prev)
        {
            if (x - a[i] < a[i] && x - a[i] >= prev)
            {
                a[i] = x - a[i];
            }
        }

        else
        {
            a[i] = x - a[i];
            if (a[i] < prev)
            {

                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    return;
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