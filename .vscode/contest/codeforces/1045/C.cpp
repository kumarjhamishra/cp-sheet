#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll minimumOperations = 0;
    for(ll i = 1; i < n; i += 2){
        ll diff = (a[i-1] + (i+1 < n ? a[i+1] : 0ll)) - a[i];
        // left right even ngbr sum > curr ele
        //cout << "diff: " << diff << endl;
        if(diff > 0){
            minimumOperations += diff;

            ll fromRight = 0;
            if(i+1 < n){
                fromRight = min(a[i+1], diff);
                a[i+1] -= fromRight;
                diff -= fromRight;
            }
            a[i-1] -= diff;
        }
    }

    cout << minimumOperations << endl;
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