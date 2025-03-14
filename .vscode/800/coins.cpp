#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
    ll n, k;
    cin >> n >> k;

    if(n % k == 0 || (n % k) % 2 == 0 || n % 2 == 0 || (n % 2) % k == 0){
        cout << "YES" << endl;
        return ;
    }
    
    // cases of both n and k odd's and both even's
    if((n % 2 == 0 && k % 2 == 0) || (n % 2 == 1 && k % 2 == 1)){
        cout << "YES" << endl;
        return ;
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