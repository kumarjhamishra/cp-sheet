#include <bits/stdc++.h>
using namespace std;
// avtobus.cpp
typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    if(n % 2 == 1 || n < 4){
        cout << -1 << endl;
        return ;
    }

    cout << (n + 4)/6 << " " << n/4 << endl;
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