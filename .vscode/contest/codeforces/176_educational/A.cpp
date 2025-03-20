#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    if(n % 2 == 1){
        int moves = 1 + (n - k) / (k-1);
        if((n - k) % (k - 1) != 0) moves += 1;
        cout << moves << endl;
        return ;
    }
    else{
        int moves = n / (k-1);
        if(n % (k - 1) != 0) moves += 1;
        cout << moves << endl;
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