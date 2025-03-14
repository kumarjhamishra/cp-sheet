#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    ll right_cnt2 = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 2) right_cnt2++;
    }

    ll left_cnt2 = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] == 2){
            left_cnt2++;
            right_cnt2--;
        }

        if(left_cnt2 == right_cnt2){
            cout << i + 1 << endl;
            return ;
        }
    }

    cout << -1 << endl;
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