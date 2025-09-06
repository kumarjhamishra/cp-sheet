#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;


void solve(){
    int n, k;
    cin >> n >> k;
    
    vi a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    ll maxGain = 0ll, preSum = 0ll, maxb = 0ll;
    // how many we want to complete - 1 to min(n, k)
    for(int i = 1; i <= min(n, k); i++){
        preSum += a[i-1];
        maxb = max(maxb, b[i-1]*1ll);
        maxGain = max(maxGain, preSum + maxb*(k-i));
    }

    cout << maxGain << endl;
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