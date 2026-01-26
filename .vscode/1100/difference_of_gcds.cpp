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
    int n, l, r;
    cin >> n >> l >> r;

    // check that is there at least one multiple of i in the range l, r for each i belongs to 1 to n
    for(int i = 1; i <= n; i++){
        if(ceil((double)l/i) > floor((double)r/i)){
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++){
        cout << (int)ceil((double)l/i) * i << " ";
    }
    cout << endl;
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