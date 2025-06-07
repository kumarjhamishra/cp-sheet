#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// odd_divisor.cpp

void solve(){
    ll n;
    cin >> n;

    while(n % 2 == 0){
        n /= 2;
    }
    if(n == 1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
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