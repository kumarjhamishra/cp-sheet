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

const int MOD = 998244353;
const int MAXN = 105;

ll fact[MAXN], invFact[MAXN];

ll power(ll base, ll exp){
    ll res = 1;
    base %= MOD;
    while(exp){
        if(exp % 2 == 1){
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }

    return res;
}

ll modInverse(ll n){
    return power(n, MOD-2);
}

void precomputeFactorials(){
    fact[0] = 1, invFact[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

void solve(){
    int n;
    cin >> n;

    vi a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    vector<pii> p(n);
    map<pii, int> originalCounts;
    for(int i = 0; i < n; i++){
        p[i] = {min(a[i], b[i]), max(a[i], b[i])};
        originalCounts[{a[i], b[i]}]++;
    }

    sort(p.begin(), p.end());

    ll ans = 1;
    for(int i = 0; i < n;){
        int j = i;
        for(; j+1 < n && p[j+1] == p[i];){
            j++;
        }
        int groupSize = j-i+1;

        ans = (ans * fact[groupSize]) % MOD;

        // if u < v -> two valid orientations for the group
        if(p[i].first != p[i].second){
            ans = (ans * 2) % MOD;
        }

        i = j+1;
    }

    for(auto i : originalCounts){
        ans = (ans * invFact[i.second]) % MOD;
    }

    cout << ans << endl;
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