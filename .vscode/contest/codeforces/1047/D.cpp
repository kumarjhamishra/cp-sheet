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

    vi b(n);
    for(auto &i : b) cin >> i;

    unordered_map<int, int> mp;
    for(int i : b) mp[i]++;

    for(auto i : mp){
        if(i.second % i.first != 0){
            cout << -1 << endl;
            return ;
        }
    }

    vi a(n);
    int ele = 1;
    unordered_map<int, vi> mp1;
    for(auto i : mp){
        vi vec;
        for(int it1 = 0; it1 < i.second / i.first; it1++){
            for(int it2 = 0; it2 < i.first; it2++){
                vec.push_back(ele);
            }
            ele++;
        }
        mp1[i.first] = vec;
    }

    for(int i = 0; i < n; i++){
        int bi = b[i];
        a[i] = mp1[bi][mp1[bi].size()-1];
        mp1[bi].pop_back();
    }

    for(int i : a) cout << i << " ";
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