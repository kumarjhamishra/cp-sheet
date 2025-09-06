#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

void solve(){
    int n;
    cin >> n;

    vector<pll> a(n);
    for(ll i = 0ll; i < n; i++){
        ll val;
        cin >> val;
        a[i] = {val, i};
    }

    sort(a.begin(), a.end());
    vll preSum(n, 0ll);
    preSum[0] = a[0].first;

    for(ll i = 1; i < n; i++){
        preSum[i] = preSum[i-1] + a[i].first;
    }

    vll ans(n);
    for(ll i = 0; i < n; i++){
        ll j = i, found = i;
        while(j < n){
            pair<ll, ll> temp = {preSum[j]+1, INT_MIN};
            ll idx = lower_bound(a.begin(), a.end(), temp) - a.begin();
            idx--;
            if(idx == j) break;
            found += idx - j;
            j = idx;
        }
        ans[a[i].second] = found;
    }

    for(auto &i : ans) cout << i << " ";
    cout << endl;
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