#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    ll n;
    cin >> n;
    
    vll b(n);
    for(ll i = 0; i < n; i++){
        // ll bi = 0;
        // cin >> bi;
        // a[i] = (1ll << bi);
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    for(ll i = 1; i < n; i++){
        if(b[i] == b[i-1]){
            cout << "YES" << endl;
            return ;
        }
    }

    cout << "NO" << endl;
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