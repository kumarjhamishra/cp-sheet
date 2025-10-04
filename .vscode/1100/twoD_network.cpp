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

void solve(){
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vvll x_y(n+1);
    for(int i = 1; i <= n; i++){
        ll x, y;
        cin >> x >> y;
        x_y[i] = {x, y};
    }

    // find one major city which is closest to city a and 
    // another major city which is closest to city b to minimize the total cost of ticket
    ll maxCost = abs(x_y[a][0] - x_y[b][0]) + abs(x_y[a][1] - x_y[b][1]);

    // base case
    if(k < 2){
        cout << maxCost << endl;
        return ;
    }
    if(a <= k && b <= k){
        cout << 0 << endl;
        return ;
    }

    // find the major city which is closest to the city 'a'
    vb taken(n+1, false);
    // find that major city which is closest to a and it's cost
    ll aToMajor = -1, costaToMajor = LLONG_MAX; 

    for(int i = 1; i <= k; i++){
        if(abs(x_y[a][0] - x_y[i][0]) + abs(x_y[a][1] - x_y[i][1]) < costaToMajor){
            costaToMajor = abs(x_y[a][0] - x_y[i][0]) + abs(x_y[a][1] - x_y[i][1]);
            aToMajor = i;
        }
    }

    taken[aToMajor] = true;
    // to avoid that a and b ends up selecting the same major city

    ll costbToMajor = LLONG_MAX; 

    for(int i = 1; i <= k; i++){
        if(abs(x_y[b][0] - x_y[i][0]) + abs(x_y[b][1] - x_y[i][1]) < costbToMajor && !taken[i]){
            costbToMajor = abs(x_y[b][0] - x_y[i][0]) + abs(x_y[b][1] - x_y[i][1]);
        }
    }

    cout << min(maxCost, costaToMajor + costbToMajor) << endl;
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