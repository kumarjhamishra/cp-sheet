#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    
    // valid range for s - k*b <= s <= k*b + n*(k-1)
    if(s < k*b || s > k*b + n*(k-1)){
        cout << -1 << endl;
        return ;
    }
    
    vector<ll> a(n, 0);
    a[0] = k*b;
    ll remainder = s - (k*b);

    // now can distribute this left over sum in all the n elements
    for(int i = 0; i < n; i++){
        a[i] += min(remainder, k-1);
        remainder -= min(remainder, k-1);
        if(remainder == 0) break;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
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