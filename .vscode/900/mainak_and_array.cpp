#include <bits/stdc++.h>
using namespace std;
//not_dividing.cpp

typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = -1e9;
    for(ll i = 0; i < n; i++){
        ans = max(ans, a[(i - 1 + n) % n] - a[i]);
    }

    for(ll i = 1; i < n; i++){
        ans = max(ans, a[i] - a[0]);
    }

    for(ll i = 0; i < n-1; i++){
        ans = max(ans, a[n-1] - a[i]);
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