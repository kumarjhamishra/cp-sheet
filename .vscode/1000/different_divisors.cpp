#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

bool checkPrime(ll n){
    if(n == 2 || n == 3) return true;
    if(n < 2 || n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i*i <= n; i += 6){
        if(n % i == 0 || n % (i+2) == 0) return false;
    }

    return true;
}

ll nextPrime(ll base){
    ll prime = base;
    while(!checkPrime(prime)){
        prime++;
    }
    return prime;
}

void solve(){
    int d;
    cin >> d;

    ll d1 = 1;
    // check with the form 1, p, q, pq where p and q are prime
    // and with the form 1, p, p^2, p^3 whichever gives smaller result
    ll d2 = nextPrime(d1 + d), d3 = nextPrime(d2 + d);

    // 1291 is the highest number whose cube is in int limit
    cout << min(d2 * d3, d2 * d2 * d2) << endl;
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