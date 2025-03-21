#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// nit_destroys.cpp

void solve(){
    // testing again
    ll n;
    cin >> n;

    vector<ll> a(n);
    bool allZero = true, noZero = true;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] != 0) allZero = false;
        if(a[i] == 0 && noZero) noZero = false;
    }

    if(allZero){
        cout << 0 << endl;
        return ;
    }
    if(noZero){
        cout << 1 << endl;
        return ;
    }
    
    // at max 2 operations are required like for eg ek baar poore ka mex le liye non zero kuch aaya
    // vo non zero value has position pe daali then again poore ka mex to ab mex 0 to sab 0

    // count consecutives segments of non zero elements
    int consecutives = 0;
    ll i = 0;
    while(i < n){
        if(a[i] == 0){
            i++;
            continue;
        }

        consecutives++;
        if(consecutives >= 2){
            cout << 2 << endl;
            return ;
        }
        while(i < n && a[i] != 0){
            i++;
        }
    }
    cout << 1 << endl;
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