#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

void solve(){
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));

    vector<p> sumOfRows;
    for(ll i = 0; i < n; i++){
        ll rowSum = 0;
        for(ll j = 0; j < m; j++){
            ll val ;
            cin >> val;
            rowSum += val;
            a[i][j] = val;
        }
        sumOfRows.push_back({rowSum, i});
    }

    sort(sumOfRows.begin(), sumOfRows.end(), greater<p>());

    ll totalSum = 0, preSum = 0;
    for(auto& i : sumOfRows){
        ll idx = i.second;

        for(ll j = 0; j < m; j++){
            totalSum += preSum + a[idx][j];
            preSum += a[idx][j];
        }
    }

    cout << totalSum << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}