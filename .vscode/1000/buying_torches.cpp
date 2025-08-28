#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    ll x, y, k;
    cin >> x >> y >> k;

    long double num = (long double)k*(y+1) - 1, denum = (long double)x-1;
    long double trade_double = ceil(num/denum) + k;
    ll trades = (ll)trade_double;
    cout << trades << endl;
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