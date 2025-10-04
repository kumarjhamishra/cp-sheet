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

bool isPossible(ll height, ll x, vll& a){
    ll totalAmountOfWater = 0ll;
    for(ll i : a){
        if(i >= height) continue;
        totalAmountOfWater += height - i;
    }

    return totalAmountOfWater <= x;
}

void solve(){
    ll n, x;
    cin >> n >> x;

    vll a(n);
    for(auto &i : a) cin >> i;

    // the range of h will be [1, (x + sum of a_i)/n]
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    sum += x;
    ll l = 1, h = sum / n, height = -1;
    while(l <= h){
        ll mid = l + ((h-l) >> 1);
        if(isPossible(mid, x, a)){
            height = mid;
            l = mid+1;
        }
        else h = mid-1;
    }

    cout << height << endl;
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