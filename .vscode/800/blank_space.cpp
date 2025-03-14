#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    // we need to find the maximum length of consecutive 0's
    int len = 0, max_len = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) len++;
        else{
            max_len = max(max_len, len);
            len = 0;
        }
    }
    max_len = max(max_len, len);
    len = 0;

    cout << max_len << endl;
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