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
    int n;
    cin >> n;

    vll a(n);
    for(auto &i : a) cin >> i;

    // 1. store all the divisors
    vi divisors;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
    }

    // 2. store the prefix sum
    vll preSum(n);
    for(int i = 0; i < n; i++){
        preSum[i] = a[i];
        if(i > 0) preSum[i] += preSum[i-1];
    }

    // 3. calculate max diff of weight sum for each k
    ll maxWeightDiff = LLONG_MIN, maxWeight = LLONG_MIN, minWeight = LLONG_MAX;
    for(int k : divisors){
        for(int i = k-1; i < n; i += k){
            ll weight = preSum[i];
            if(i-k >= 0) weight -= preSum[i-k];
            maxWeight = max(maxWeight, weight);
            minWeight = min(minWeight, weight);
        }
        maxWeightDiff = max(maxWeightDiff, maxWeight - minWeight);
        maxWeight = LLONG_MIN, minWeight = LLONG_MAX;
    }
    cout << maxWeightDiff << endl;
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