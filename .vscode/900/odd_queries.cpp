#include <bits/stdc++.h>
using namespace std;
// odd_queries.cpp
typedef long long ll;

void solve(){
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n), prefix(n, 0);
    ll total_sum = 0;
    for(ll i = 0; i < n; i++){ 
        cin >> a[i];
        total_sum += a[i];
        prefix[i] = total_sum;
    }

    for(ll i = 0; i < q; i++){
        ll l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        ll range_sum = prefix[r] - (l == 0 ? 0 : prefix[l-1]);
        if((total_sum - range_sum + (r - l + 1) * k) % 2 == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return ;

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