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

    vector<ll> p(n);
    ll k = 0;
    for(ll i = 0; i < n; i++){
        cin >> p[i];
        k = gcd(k, abs(i + 1 - p[i]));
    }

    cout << k << endl;
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