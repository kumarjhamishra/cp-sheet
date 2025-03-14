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

    // if the minimum and maximum element are same then we can't make the array beautiful
    if(a[0] == a[n-1]){
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;
    // at first place put the maximum and at the second place put the minimum
    // else all things will be correct automatically
    swap(a[0], a[1]);
    swap(a[0], a[n-1]);
    for(ll i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
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