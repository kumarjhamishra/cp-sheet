#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
#define pb push_back

void solve(){
    // parity of count of negative numbers won't change
    ll n;
    cin >> n;
    vll a(n);
    for(auto &i : a) cin >> i;

    ll tot = 0ll, miniAbs = 1e9, cnt = 0;
    for(int i = 0; i < n; i++){
        tot += abs(a[i]);
        miniAbs = min(miniAbs, abs(a[i]));
        if(a[i] < 0) cnt++;
    }

    if(cnt % 2){
        tot -= 2*miniAbs;
    }
    cout << tot << endl;
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