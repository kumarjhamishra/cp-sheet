#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin >> k;

    if(k % 2 == 1){
        cout << "YES" << endl;
        return;
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