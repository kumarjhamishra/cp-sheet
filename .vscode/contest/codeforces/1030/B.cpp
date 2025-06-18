#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> moves;

    int l = 1, r = n-1;
    while(l <= n){
        int ls = 1, le = l, rs = l+1, re = n, row = l;
        if(le - ls > 0){
            moves.push_back({row, ls, le});
        }
        if(rs <= n && re - rs > 0){
            moves.push_back({row, rs, re});
        }
        l += 1;
    }

    cout << moves.size() << endl;
    for(auto i : moves){
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
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