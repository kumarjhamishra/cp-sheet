#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

void solve(){
    int n;
    cin >> n;

    vi p(n);
    for(auto &i : p) cin >> i;

    // we will make the sum = n+1 so qi = n+1 - pi
    // this way the gcd will always becomes n+1
    for(int i = 0; i < n; i++) cout << (n+1) - p[i] << " ";
    cout << endl;

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