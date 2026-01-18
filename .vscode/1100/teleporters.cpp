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
    ll n, c;
    cin >> n >> c;
    vll a(n);


    for(auto &i : a) cin >> i;

    // need to calculate total cost for each point
    for(int i = 0; i < n; i++){
        a[i] += (i+1);
    }

    sort(a.begin(), a.end());

    ll currCost = 0ll;
    for(int i = 0; i < n; i++){
        if(currCost + a[i] <= c) currCost += a[i];
        else{
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
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