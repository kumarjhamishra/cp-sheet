#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0) return a;

    return gcd(b, a % b);
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    // now we need to find the 2 elements whose gcd will be <= 2 and then done
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            if(gcd(a[i], a[j]) <= 2){
                cout << "YES" << endl;
                return ;
            }
        }
    }

    cout << "NO" << endl;
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