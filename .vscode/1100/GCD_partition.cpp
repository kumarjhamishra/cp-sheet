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
    int n;
    cin >> n;

    vll a(n);
    for(auto &i : a) cin >> i;

    vll prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + a[i];

    /*
    the catch here is to figure out that making subsegments > 2 will never be feasible.
    Therefore the max subsegments we need is 2
    */
    ll sum = prefix[n-1], maxGCD = -1e9;
    for(int i = 0; i < n-1; i++){
        maxGCD = max(maxGCD, __gcd(prefix[i], sum - prefix[i]));
    }

    cout << maxGCD << endl;
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