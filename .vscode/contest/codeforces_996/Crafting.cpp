#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int deficitIdx = -1, need = 0, margin = 1e9;
    for(int i = 0; i < n; i++){
        if(b[i] > a[i]){
            if(deficitIdx != -1){
                cout << "NO" << endl;
                return ;
            }
            deficitIdx = i;
            need = b[i] - a[i];
        }
        else{
            margin = min(margin, a[i] - b[i]);
        }
    }


    cout << ((margin >= need) ? "YES" : "NO") << endl;
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