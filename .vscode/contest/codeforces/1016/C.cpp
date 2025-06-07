#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, k;
    cin >> x >> k;


    if(x == 1){
        if(k == 2){
            cout << "YES" << endl;
            return ;
        }
        cout << "NO" << endl;
        return ;
    }

    // if the number is initially not prime - it's k times duplication will also not be prime
    for(ll i = 2; i*i <= x; i++){
        if(x % i == 0){
            cout << "NO" << endl;
            return ;
        }
    }

    // came here means x is prime of 4 and 4 se bara

    if(k == 1){
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