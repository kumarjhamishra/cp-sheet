#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n;
    cin >> n;

    // we need to find that power of 2 let's say k which is just less than n
    // for eg - n = 10, k = 8

    // base case
    if(n == 2){
        cout << 0 << " " << 1 << endl;
        return ;
    }

    int k = 0;
    for(int i = 30; i >= 1; i--){
        if((1 << i) < n){
            k = (1 << i);
            break;
        }
    }

    for(int i = k-1; i >= 0; i--) cout << i << " ";
    for(int i = k; i < n; i++) cout << i << " ";
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