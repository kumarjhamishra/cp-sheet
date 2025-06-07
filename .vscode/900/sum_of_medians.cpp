#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// sum_of_medians.cpp

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n*k);
    for(int i = 0; i < n*k; i++){
        cin >> a[i];
    }

    int m = n*k, mid_part = (n/2 + 1);
    ll sum_of_medians = 0;
    for(int i = 1; i <= k; i++){
        sum_of_medians += a[m - mid_part*i];
    }

    cout << sum_of_medians << endl;
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