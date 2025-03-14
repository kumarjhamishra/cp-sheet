#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll xor_ = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        xor_ ^= a[i];
    }
    ll ans = n % 2 == 0 && xor_ != 0 ? -1 : xor_;
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