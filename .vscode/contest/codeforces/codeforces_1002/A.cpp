#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    set<int> as, bs;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        a[i] = val;
        as.insert(val);
    }

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        b[i] = val;
        bs.insert(val);
    }

    int asize = as.size(), bsize = bs.size();
    if((asize == 1 && bsize == 1) || (asize == 1 && bsize == 2) || (asize == 2 && bsize == 1)){
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}