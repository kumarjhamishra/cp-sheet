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
const int MOD = 1E9+7;

void solve(){
    ll n;
    cin >> n;

    // the formula brings down to n * (n+1) * (4n-1) * 337
    ll ans = n % MOD;
    ans = (ans * ((n + 1) % MOD)) % MOD;
    ans = (ans * ((4 * n - 1) % MOD)) % MOD;
    ans = (ans * 337) % MOD;
    cout << ans << endl;
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