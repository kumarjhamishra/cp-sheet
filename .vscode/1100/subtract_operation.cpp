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

    int l = 0, r = 1;
    while(l < r && r < n){
        int diff = a[r] - a[l];
        if(diff == k){
            cout << "YES" << endl;
            return ;
        }
        else if(diff < k) r++;
        else{
            l++;
            if(l >= r) r = l+1;
        }
    }

    cout << "NO" << endl;
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