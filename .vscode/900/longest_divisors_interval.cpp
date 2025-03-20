#include <bits/stdc++.h>
using namespace std;
//longest_divisors_interval.cpp
typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    ll i = 1;
    while(n % i == 0) {i++;}

    cout << i - 1 << endl;
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