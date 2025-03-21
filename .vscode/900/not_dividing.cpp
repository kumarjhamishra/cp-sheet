#include <bits/stdc++.h>
using namespace std;
//not_dividing.cpp
 
typedef long long ll;
 
void solve(){
    ll n;
    cin >> n;
 
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
 
    // base case
    if(n == 1){
        cout << a[0] << endl;
        return ;
    }
 
    for(ll i = 0; i < n-1; i++){
        if(a[i] > a[i+1]) continue;
 
        if(a[i] == 1){
            a[i]++;
            if(i-1 >= 0 && a[i - 1] == a[i]) a[i]++;
        }
 
        if(a[i+1] % a[i] == 0){
            a[i+1] += 1;
        }
    }
 
    for(ll i : a){
        cout << i << " ";
    }
    cout << endl;
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