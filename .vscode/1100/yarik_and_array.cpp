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

    vi a(n);
    for(auto &i : a) cin >> i;

    ll maxSum = LLONG_MIN, currSum = 0ll;
    for(int i = 0; i < n; i++){
        if(i > 0 && abs(a[i]) % 2 == abs(a[i-1]) % 2){
            currSum = 0ll;
            //cout << "a[i]: " << a[i] << endl;
        }
        currSum += a[i];
        currSum = max(currSum, a[i]*1ll);
        maxSum = max(maxSum, currSum);
        //cout << "currSum: " << currSum << " " << "maxSum: " << maxSum << endl;
    }
    cout << maxSum << endl;
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