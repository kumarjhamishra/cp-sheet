#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
// balanced_round.cpp

void solve(){
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll max_count = 0, current_count = 1;

    for (ll i = 1; i < n; i++) {
        if (a[i] - a[i - 1] <= k) {
            current_count++;
        } else {
            max_count = max(max_count, current_count);
            current_count = 1;
        }
    }
    max_count = max(max_count, current_count);

    cout << n - max_count << endl;
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