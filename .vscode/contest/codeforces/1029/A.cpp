#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int cntClose = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) cntClose++;
    }

    // base case
    if(cntClose == 1){
        cout << "YES" << endl;
        return ;
    }

    cntClose = 0;
    int i = 0;
    while(i < n){
        if(a[i] == 1){
            break;
        }
        i++;
    }
    int j = n-1;
    while(j >= 0){
        if(a[j] == 1){
            break;
        }
        j--;
    }

    int total1 = j - i + 1;
    if(x >= total1){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

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