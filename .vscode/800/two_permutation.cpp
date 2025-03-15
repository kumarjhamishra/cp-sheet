#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;

    if(n == 1 || a + b + 2 <= n || (a == n && b == n)){
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