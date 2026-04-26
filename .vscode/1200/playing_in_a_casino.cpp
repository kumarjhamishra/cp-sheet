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
    int n, m;
    cin >> n >> m;
    vvi c(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int ele;
            cin >> ele;
            c[i][j] = ele;
        }
    }

    /*
    sum = sigma (all pairs) sigma (j=1->m) | c_ij - c_ik |
    => sigma (j=1->m) (sigma (i, k) | c_ij - c_ik |)
    for a jth posn total contirbution of an element in sum = 
    (elements in it's left - elements in it's right) * element
    */
    ll potSize = 0ll;
    for(int j = 0; j < m; j++){
        vi a;
        for(int i = 0; i < n; i++){
            a.push_back(c[i][j]);
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            // ll contribution = ((i - 0) - (n-1-i)) * a[i] * 1ll;
            ll contribution = (1ll * i - (n-1-i)) * a[i];
            potSize += contribution;
        }
    }

    cout << potSize << endl;
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