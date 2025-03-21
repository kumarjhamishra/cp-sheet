#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b, n;
    cin >> a >> b >> n;

    vector<ll> x(n);
    ll ans = b;
    for(ll i = 0; i < n; i++){
        cin >> x[i];
        ans += min(a - 1, x[i]);
    }

    cout << ans << endl;
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