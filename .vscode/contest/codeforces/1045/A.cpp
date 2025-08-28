#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    if(a <= b){
        cout << ((n % 2) == (b % 2) ? "YES" : "NO") << endl;
    }
    else{
        cout << ((n % 2) == (b % 2) && (n % 2) == (a % 2) ? "YES" : "NO") << endl;
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