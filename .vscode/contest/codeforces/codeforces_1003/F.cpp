#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;
using vvll = vector<vll>;

// const ll MAXN = 5E5 + 16;
// vvll adj(MAXN);

void solve(){
    ll n;
    cin >> n;
    vll ve(n);

    for(ll &i : ve) cin >> i, i--;
    
    //adj.resize(n);
    vvll adj(n);

    for(ll i = 1; i < n; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string ans(n, '0');

    // we can get the x as a majority in a sequence in only 2 cases - [x, x] and [x, y, x]
    for(ll u = 0; u < n; u++){
        map<ll, ll> mp;
        for(ll v : adj[u]){
            mp[ve[v]]++;
        }
        mp[ve[u]]++;
        for(auto i : mp){
            if(i.second >= 2) ans[i.first] = '1';
            //cout << "u: " << u << " " <<  i.first << " " << i.second << endl;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}