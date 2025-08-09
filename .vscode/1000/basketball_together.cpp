#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    ll n, d;
    cin >> n >> d;
    vll p(n);
    for(ll i = 0; i < n; i++){
        cin >> p[i];
    }
    //cout << "hello" << endl;
    
    //d += 1; // to maintain strictly greater condition
    sort(p.begin(), p.end(), greater<ll>());
    ll maxWins = 0, l = 0, r = n-1;
    while(l <= r){
        // players required
        ll playersCount = d / p[l] + 1;

        // 1 from left and rest others from right
        r -= playersCount - 1;
        if(r < l) break;
        l++;
        maxWins++;
    }

    cout << maxWins << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    // int t;
    // cin >> t;
    // while(t--){
    // }

    return 0;
}