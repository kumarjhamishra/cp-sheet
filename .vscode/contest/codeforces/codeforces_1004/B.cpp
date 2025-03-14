#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    vector<int> a(1002, 0);
    int minIdx = INT_MAX;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        a[val]++;
        minIdx = min(minIdx, val);
    }

    int prevExtra = 0;
    for(int i = minIdx; i <= 1001; i++){
        a[i] += prevExtra;

        if(a[i] == 1){
            //cout << "first and i : " << i << endl;
            cout << "NO" << endl;
            return ;
        }

        if(a[i] > 2){
            prevExtra = a[i] - 2;
            a[i] -= prevExtra;
        }
        else prevExtra = 0;
    }

    // for the last element at index 1001
    a[1001] += prevExtra;

    for(int i = minIdx; i <= 1001; i++){
        if(a[i] % 2 == 1){
            //cout << "2nd" << endl;
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
    return ;
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