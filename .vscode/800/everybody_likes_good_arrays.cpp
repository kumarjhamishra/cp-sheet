#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    // we need to check the consecutive's odd's and even's to calculate the operations needed
    ll operations = 0, count_odd = 1, count_even = 1, last_odd = -1;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        
        // case of odd
        if(a[i] % 2 != 0){
            // last element was also odd
            if(last_odd == 1){
                count_odd++;
            }
            // last element was even - count the operations for previos consecutive's even's
            else{
                operations += count_even - 1;
                count_even = 0;
                count_odd = 1;
                last_odd = 1;
            }
        }
        // even
        else{
            // last element was also even
            if(last_odd == 0) count_even++;
            else{
                operations += count_odd - 1;
                count_odd = 0;
                count_even = 1;
                last_odd = 0;
            }
        }
    }

    if(count_odd > 0){
        operations += count_odd - 1;
    }
    else if(count_even > 0){
        operations += count_even - 1;
    }

    cout << operations << endl;
    return ;
}
*/


// more optimised approach
void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll operations = 0;
    for(ll i = 0; i < n-1; i++){
        operations += !((a[i] ^ a[i+1]) & 1);
    }

    cout << operations << endl;
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