#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpllll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define pb push_back

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto &i : a) cin >> i;
    int x;
    cin >> x;

    int mini = 1e9, maxi = -1e9;
    for(int i = 0; i < n; i++){
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
    }

    if(mini <= x && x <= maxi){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
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