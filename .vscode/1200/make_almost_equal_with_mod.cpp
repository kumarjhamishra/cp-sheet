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

int f(vll &a, ll &k){
    set<ll> distinct;

    for(auto i : a){
        distinct.insert(i % k);
    }
    return distinct.size();
}

void solve(){
    int n;
    cin >> n;

    vll a(n);
    for(auto &i : a) cin >> i;

    bool allEven = all_of(a.begin(), a.end(), [](ll x) {return x % 2 == 0;});
    bool allOdd = all_of(a.begin(), a.end(), [](ll x) {return x % 2 != 0;});

    if(!allEven && !allOdd){
        cout << 2 << endl;
        return ;
    }
    
    // if a_i mod k = x
    /*
    then a_i mod 2k = x
    or a_i mod 2k = x + k
    f(k) = total distinct elements in the array after the mod operation
    so for a k if f(k) = 1 then f(2k) = 1 (all were x or all were x+k) or 2 (some x and some x+k)
    2^57 > 1e17
    */
    for(ll i = 2; i <= 57; i++){
        ll k = (1ll << i);
        if(f(a, k) == 2){
            cout << k << endl;
            return ;
        }
    }
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