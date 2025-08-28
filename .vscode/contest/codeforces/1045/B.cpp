#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for(auto &i : a) cin >> i;

    // g can be at max 29
    for(int g = 2; g <= 29; g++){
        if(__gcd(g, k) != 1){
            continue;
        }

        // to make all the final elements divisible by k
        for(auto &i : a){
            while(i % g != 0) i += k;
        }

        for(auto i : a){
            cout << i << " ";
        }
        cout << endl;
        break;
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