#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for(auto &i : a) cin >> i;

    //sort(a.begin(), a.end());
    sort(a.begin(), a.end(), greater<int>());

    for(auto &i : a) cout << i << " ";
    cout << endl;
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