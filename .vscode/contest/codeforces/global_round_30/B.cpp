#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpllll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define pb push_back

void solve(){
    int n;
    cin >> n;

    vll a(n);
    for(auto &i : a) cin >> i;

    ll even = -1, odd = -1;

    for(int i = 0; i < n; i++){
        // y is even
        if(a[i] % 2 == 0){
            if(even != -1){
                cout << even << " " << a[i] << endl;
                return ;
            }
            if(odd != -1 && (a[i] % odd) % 2 == 0){
                cout << odd << " " << a[i] << endl;
                return ;
            }
        }
        // y is odd
        if(odd != -1 && (a[i] % odd) % 2 == 0){
            cout << odd << " " << a[i] << endl;
            return ;
        }
        

        if(a[i] % 2 == 0 && even == -1) even = a[i];
        if(a[i] % 2 != 0 && odd == -1) odd = a[i];
    }

    cout << -1 << endl;
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}