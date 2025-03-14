#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, k;

    cin >> x >> k;

    if(x < k){
        cout << 1 << endl;
        cout << x << endl;
        return ;
    }

    if(x % k == 0){
        cout << 1 << endl;
        cout << x << endl;
        return ;
    }
    else{
        cout << 2 << endl;
        cout << x-1 << " " << 1 << endl;
        return ;
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