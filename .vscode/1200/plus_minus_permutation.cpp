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
    ll n, x, y;
    cin >> n >> x >> y;

    // no of multiples of x in range [1, n] = floor(n/x)
    ll with_x = n/x, with_y = n/y;
    // total indices in range [1, n] which will be divisible by both 1 and n = floor(n/LCM(x, y))
    ll lcm_xy = (x/__gcd(x, y)) * y; // to avoid overflow
    ll with_both = n/lcm_xy;

    // score = sum of elements at indcices only divisble by x  - sum of elements at indcices only divisble by y
    ll n1 = n - (with_x - with_both), n2 = with_y - with_both;
    ll s1 = ((n*(n+1))/2) - ((n1*(n1+1))/2);
    ll s2 = (n2*(n2+1))/2;

    cout << s1 - s2 << endl;
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