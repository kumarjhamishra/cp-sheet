#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// make_it_increasing.cpp

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    // check for already stricly increasing
    int prev = INT_MIN;
    bool strictlyIncreasing = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] <= prev) strictlyIncreasing = false;
        else{
            prev = a[i];
        }
    }

    if(n == 1 || strictlyIncreasing){
        cout << 0 << endl;
        return ;
    }

    int moves = 0;
    for(int i = n-2; i >= 0; i--){
        while(a[i] >= a[i+1] && a[i] > 0){
            moves++;
            a[i] /= 2;
        }
        if(a[i] == a[i+1]){
            cout << -1 << endl;
            return ;
        }
    }

    cout << moves << endl;
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