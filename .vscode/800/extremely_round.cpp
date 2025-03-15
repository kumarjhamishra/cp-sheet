#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    if(n >= 1 && n <= 9){
        cout << n << endl;
        return ;
    }
    else if(n >= 10 && n <= 99){
        cout << n / 10 + 9  << endl;
        return ;
    }
    else if(n >= 100 && n <= 999){
        cout << n / 100 + 18 << endl;
        return ;
    }
    else if(n >= 1000 && n <= 9999){
        cout << n / 1000 + 27 << endl;
        return ;
    }

    else if(n >= 10000 && n <= 99999){
        cout << n / 10000 + 36 << endl;
        return ;
    }
    else if(n >= 100000 && n <= 999999){
        cout << n / 100000 + 45 << endl;
        return ;
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