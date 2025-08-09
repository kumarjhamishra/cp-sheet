#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    ll n, x;
    cin >> n >> x;

    vll a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // for each ai the valid range of v will be ai - x <= v <= ai + x
    // common range
    int cs = a[0] - x, ce = a[0] + x, changes = 0;
    for(int i = 1; i < n; i++){
        // non intersecting
        int s = a[i] - x, e = a[i] + x;
        if(s > ce || e < cs){
            changes++;
            cs = s, ce = e;
        }
        // intersecting
        else{
            cs = max(cs, s), ce = min(ce, e);
        }
    }
    cout << changes << endl;
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