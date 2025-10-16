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

const int mod = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // now for each a_i store the total elements in b which are smaller than a_i
    vi countSmaller;
    for(int i = 0; i < n; i++){
        // lower boudn gives iterator to the first element >= a[i] in b
        int count = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        countSmaller.push_back(count);
    }

    // cout << "printing count" << endl;
    // for(int count : countSmaller){
    //     cout << count << " ";
    // }
    // cout << endl;
    ll totalWays = 1ll;
    for(int i = 0; i < n; i++){
        int count = countSmaller[i] - i;
        totalWays = ((totalWays % mod) * (count % mod)) % mod;
    }

    cout << totalWays << endl;
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