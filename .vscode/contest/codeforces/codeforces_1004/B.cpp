#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(1002, 0);
    ll mini = LLONG_MAX;
    for(int i = 0; i < n; i++){
        ll val;
        cin >> val;
        a[val]++;
        mini = min(mini, val);
    }
    
    for(ll i = mini; i <= 1000; i++){
        if(a[i] == 1){
            cout << "NO" << endl;
            return ;
        }
        else{
            a[i+1] += a[i] - 2;
            a[i] = 2;
        }
    }

    for(ll i = mini; i <= 1001; i++){
        if(a[i] % 2 != 0){
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}