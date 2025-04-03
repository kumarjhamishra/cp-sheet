#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// old_grasshopper.cpp

void solve(){
    ll x, n;
    cin >> x >> n;

    ll base_number = 4 * (n / 4);
    ll remaining = n % 4;
    if(x % 2 == 0){

        if(remaining == 0){
            cout << x << endl;
            return ;
        }
        else if(remaining == 1){
            cout << x - (base_number + 1) << endl;
            return ;
        }
        else if(remaining == 2){
            cout << x - (base_number + 1) + (base_number + 2) << endl;
            return ;
        }
        else{
            cout << x - (base_number + 1) + (base_number + 2) + (base_number + 3) << endl;
            return ;
        }
    }

    else{
        if(remaining == 0){
            cout << x << endl;
            return ;
        }
        else if(remaining == 1){
            cout << x + (base_number + 1) << endl;
            return ;
        }
        else if(remaining == 2){
            cout << x + (base_number + 1) - (base_number + 2) << endl;
            return ;
        }
        else{
            cout << x + (base_number + 1) - (base_number + 2) - (base_number + 3) << endl;
            return ;
        }
    }
    
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