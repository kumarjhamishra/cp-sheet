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
    ll a, b;
    cin >> a >> b;

    // cases of parity
    
    // try to make b smallest and a largest to maximize the even sum
    if(a % 2 == 0 && b % 2 == 0){
        // the optimal k will be b/2
        cout << a * (b/2) + 2 << endl;
        return ;
    }
    if(a % 2 == 0 && b % 2 == 1){
        // if b is odd so it has no even divisor so b' = b/k (odd/odd) = odd
        // and even + odd = odd
        cout << -1 << endl;
        return ;
    }
    if(a % 2 == 1 && b % 2 == 0 && b % 4 != 0){
        // a odd, b divisible by 2 but not by 4
        // means b has only 1 factor of 2 which will finish on b/k and b' -> odd
        // and a' = a * (2*(some number)) = even and even + odd = odd
        cout << -1 << endl;
    }
    if(a % 2 == 1 && b % 2 == 0 && b % 4 == 0){
        // b divisible by 4
        // so b' = b/k even
        cout << a * (b/2) + 2 << endl;
        return ; 
    }
    if(a % 2 == 1 && b % 2 == 1){
        // a' = a*k = odd, b' = b/k odd
        // odd + odd = even so any k will be valid
        // maximum k possible = b
        cout << a*b + 1 << endl;
        return ;
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