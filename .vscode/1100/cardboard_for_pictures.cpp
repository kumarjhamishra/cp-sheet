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

ll calculateArea(ll w, vll& s, ll c){
    ll totalArea = 0ll;
    // to avoid any kind of overflow break the loop just as totalArea > c 
    for(ll s_i : s){
        totalArea += (s_i + w + w) * (s_i + w + w);
        if(totalArea > c) break;
    }

    return totalArea;
}

void solve(){
    ll n, c;
    cin >> n >> c;

    vll s(n);
    for(auto &i : s) cin >> i;

    // w ranges from 1 to 1e9 at max
    ll l = 1, h = 1e9;
    while(l <= h){
        ll mid = l + (h-l)/2;
        ll totalArea = calculateArea(mid, s, c);
        // cout << "l: " << l << " h: " << h << " mid: " << mid << endl;
        // cout << "totalArea : " << totalArea << endl;
        if(totalArea == c){
            cout << mid << endl;
            return ;
        }
        else if(totalArea < c) l = mid+1;
        else h = mid-1;
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