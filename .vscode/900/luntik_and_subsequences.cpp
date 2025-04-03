#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// luntik_and_subsequences.cpp



void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    // to make sum of subsequences equal to total sum - 1 we can remove only 1 some 0's
    // so total ways = pow(2, total 0's) * total 1's
    ll cnt0 = 0, cnt1 = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) cnt0++;
        else if(a[i] == 1) cnt1++;
    }

    cout << 1ll * (1ll << cnt0) * cnt1 << endl;

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