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

vi threeBest(vi& a, int &n){
    int mx1 = -1, mx2 = -1, mx3 = -1;
    for(int i = 0; i < n; i++){
        if(mx1 == -1 || a[i] > a[mx1]){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }
        else if(mx2 == -1 || a[i] > a[mx2]){
            mx3 = mx2;
            mx2 = i;
        }
        else if(mx3 == -1 || a[i] > a[mx3]){
            mx3 = i;
        }
    }

    return {mx1, mx2, mx3};
}

void solve(){
    int n;
    cin >> n;

    vi a(n), b(n), c(n);
    for(auto &i : a){
        cin >> i;
    }
    for(auto &i : b){
        cin >> i;
    }
    for(auto &i : c){
        cin >> i;
    }
    
    // find the three best maximum from each list
    vi bestOfA = threeBest(a, n), bestOfB = threeBest(b, n), bestOfC = threeBest(c, n);

    ll ans = -1e9;
    for(int i : bestOfA){
        for(int j : bestOfB){
            for(int k : bestOfC){
                if(i != j && i != k && j != k){
                    ans = max(ans, (a[i] + b[j] + c[k]) * 1ll);
                }
            }
        }
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