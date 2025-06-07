#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b;
    cin >> a >> b;

    // base cases
    if(a == b || a == 0 || b == 0){
        ll max_gcd = a == b ? 0 : max(a, b);
        cout << max_gcd << " " << 0 << endl;
        return ;
    }

    ll max_num = max(a, b), min_num = min(a, b), max_gcd = max_num - min_num;
    ll remainder = max_num % max_gcd;
    ll min_moves = min(remainder, max_gcd - remainder);
    
    cout << max_gcd << " " << min_moves << endl;
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