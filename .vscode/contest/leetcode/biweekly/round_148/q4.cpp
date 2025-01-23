#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
private:
    const int mod = 1e9+7;

    // a ^ b
    ll power(ll a, ll b){
        ll ans = 1;
        a %= mod;
        while(b){
            if(b & 1){
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }

        return ans;
    }

    // mod multiplication (a*b) mod
    ll modmul(ll a, ll b){
        ll c = a * b;
        c %= mod;
        return c;
    }

    // mod division (a/b) mod = (a * b inverse) mod m
    ll moddiv(ll a, ll b){
        ll c = a;
        // b inverse = (b ^ (mod m-2)) mod m 
        c = c * power(b, mod-2);
        c %= mod;
        return c;
    }
public:
    int distanceSum(int m, int n, int k) {
        // we need mn-2 C k-2
        // taking N = m*n so it becomes (N-2)! / (N-k)! * (k-2)!
        ll N = m*n;
        vector<ll> fact(N+1, 0);
        fact[0] = 1;
        for(ll i = 1; i <= N; i++){
            fact[i] = modmul(fact[i-1], i);
        }

        ll contributionOfEachSum = moddiv(fact[N-2], modmul(fact[N-k], fact[k-2])); 

        // sum of all (x1, x2) pairs = (n^2 * m*(m-1)*(m+1))/6;
        ll xDistanceSum = 1;
        xDistanceSum = modmul(xDistanceSum, m);
        xDistanceSum = modmul(xDistanceSum, m-1);
        xDistanceSum = modmul(xDistanceSum, m+1);
        // now n*2
        xDistanceSum = modmul(xDistanceSum, n);
        xDistanceSum = modmul(xDistanceSum, n);
        xDistanceSum = moddiv(xDistanceSum, 6);

        // similarly for sum of all pairs of (y1, y2)
        ll yDistanceSum = 1;
        yDistanceSum = modmul(yDistanceSum, n);
        yDistanceSum = modmul(yDistanceSum, n-1);
        yDistanceSum = modmul(yDistanceSum, n+1);
        yDistanceSum = modmul(yDistanceSum, m);
        yDistanceSum = modmul(yDistanceSum, m);
        yDistanceSum = moddiv(yDistanceSum, 6);

        ll totalSum = xDistanceSum + yDistanceSum;
        ll finalAns = modmul(totalSum, contributionOfEachSum);

        return finalAns;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        //solve();
    }

    return 0;
}