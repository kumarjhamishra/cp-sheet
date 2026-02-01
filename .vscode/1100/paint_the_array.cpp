#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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

    vll a(n);
    for(auto &i : a) cin >> i;

    vll g(a.begin(), a.begin()+2);
    for(int i = 0; i < n; i++){
        g[i % 2] = __gcd(g[i % 2], a[i]);
    }

    vb good(2, true);
    for(int i = 0; i < n; i++){
        good[i % 2] = good[i % 2] && (a[i] % g[(i % 2) ^ 1] > 0);
    }

    ll ans = 0;
    for(int i = 0; i < 2; i++){
        if(good[i]) ans = max(ans, g[i ^ 1]);
    }

    cout << ans << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}