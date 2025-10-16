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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    vll pre(n);
    pre[0] = a[0] * 1ll;
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + a[i];
    }

    // 0 <= k1 <= k and k2 will also be from 0 to k
    ll sum = 0ll, currSum = 0ll;
    for(int i = 0; i <= k; i++){
        currSum = pre[n-1-k+i];
        if(i > 0) currSum -= pre[2*i-1];
        sum = max(sum, currSum);
    }

    cout << sum << endl;
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