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
    int n, k;
    cin >> n >> k;

    vi a(n);
    for(auto &i : a) cin >> i;
    vi b(k);
    for(auto &i : b) cin >> i;

    // a in decreasing and b in increasing
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    // for(int i : a) cout << i << " ";
    // cout << endl;
    // for(int i : b) cout << i << " ";
    // cout << endl;

    // we need the prefix sum array
    vll prefixSum(n, 0ll);
    prefixSum[0] = a[0] * 1ll;
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    // for(ll i : prefixSum) cout << i << " ";
    // cout << endl;

    int i = 0, j = 0;
    ll totalPrices = 0ll;
    while(j < k && i < n){
        // first take the sum from index i to i+b[j]-1
        ll currentSum = prefixSum[min(i+b[j]-1, n-1)];
        if(i > 0) currentSum -= prefixSum[i-1];
        
        // remove the price of last element taken
        if(n-i >= b[j]) currentSum -= a[i+b[j]-1];
        totalPrices += currentSum;
        i += b[j];
        j++;
    }

    if(i < n){
        totalPrices += prefixSum[n-1];
        if(i > 0) totalPrices -= prefixSum[i-1];
    }

    cout << totalPrices << endl;
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