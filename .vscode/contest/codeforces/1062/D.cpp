#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
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
    int n;
    cin >> n;

    vll a(n);
    for(auto &i : a) cin >> i;

    // find the gcd of entire array
    ll G = a[0];
    for(ll i : a) G = __gcd(G, i);

    /*
    The product of the first 16 primes (2, 3, 5, ... 53) is already 
    greater than 1e18. This means G cannot be divisible by all 
    primes up to 53.
    */
    ll x = 2;
    while(__gcd(G, x) != 1){
        // runs at max 53 times
        x++;
    }

    cout << x << endl;
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