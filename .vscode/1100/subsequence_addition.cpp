#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define pb push_back

void solve(){
    int n;
    cin >> n;

    vi c(n);
    for(auto &i : c) cin >> i;

    if(n == 1){
        cout << (c[0] == 1 ? "YES" : "NO") << endl;
        return ;
    }

    // n >= 2
    sort(c.begin(), c.end());
    if(c[0] != 1 || c[1] != 1){
        cout << "NO" << endl;
        return ;
    }

    ll sum = 2;
    for(int i = 2; i < n; i++){
        if(c[i] > sum){
            cout << "NO" << endl;
            return ;
        }
        sum += c[i];
    }
    cout << "YES" << endl;
    return ;
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