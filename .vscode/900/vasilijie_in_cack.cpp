#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;

    // we can obtain any sum taking k elements which is in the range of smallest sum and largest sum taking k elements
    // smallest sum
    ll small_sum = k * (k + 1) / 2;
    // largest sum
    ll large_sum = (n * (n + 1) - (n - k) * (n - k + 1)) / 2;

    if(x < small_sum || x > large_sum){
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;
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