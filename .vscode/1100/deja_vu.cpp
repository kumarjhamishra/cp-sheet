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
    int n, q;
    cin >> n >> q;

    vll a(n);
    for(auto &i : a) cin >> i;
    vi x(q);
    for(auto &i : x) cin >> i;

    int minProcessed_xi = 31;
    for(int i : x){
        if(i >= minProcessed_xi){
            continue;
        }
        else{
            for(int j = 0; j < n; j++){
                if(a[j] % (1ll << i) == 0){
                    a[j] += (1ll << (i-1));
                }
            }

            minProcessed_xi = i;
        }
    }

    for(ll i : a) cout << i << " ";
    cout << endl;

    // T.C - O(30*n)
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