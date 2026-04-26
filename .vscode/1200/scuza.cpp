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
    int n, q;
    cin >> n >> q;
    vi a(n), k(q);
    for(auto &i : a) cin >> i;
    for(auto &i : k) cin >> i;
    
    
    /*
    vector<pll> b;
    b.push_back({a[0], a[0]});
    for(int i = 1; i < n; i++){
        ll last_height = b[i-1].second;
        b.push_back({a[i], last_height + a[i]});
    }

    map<ll, ll> mp;
    for(int i : k) mp[i] = 0;
    
    int j = 0;
    for(auto &i : mp){
        // if(i.first < b[0].first){
        //     i.second = 0;
        //     cout << "hello inside if" << endl;
        //     cout << i.first << " " << b[0].first << endl;
        //     continue;
        // }
        while(j < n && i.first >= b[j].first){
            j++;
        }
        if(j-1 >= 0) i.second = b[j-1].second;
        //cout << "hello" << endl;
        //cout << i.first << " " << i.second << endl;
    }

    // for(auto i : mp){
    //     cout << i.second << " ";
    // }
    for(int i : k){
        cout << mp[i] << " ";
    }
    cout << endl;
    */


    // approach 2
    vll pre;
    vi preMax;
    pre.push_back(a[0]);
    preMax.push_back(a[0]);

    for(int i = 1; i < n; i++){
        pre.push_back(pre.back() + a[i]);
        preMax.push_back(max(preMax.back(), a[i]));
    }

    for(int k_i : k){
        int ind = upper_bound(preMax.begin(), preMax.end(), k_i) - preMax.begin();
        if(ind == 0) cout << 0 << " ";
        else cout << pre[ind-1] << " ";
    }
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