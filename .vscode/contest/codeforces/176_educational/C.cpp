#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bs(vector<ll>& a, ll m, ll num){
    ll ans = -1, l = 0, r = m-1;

    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(a[mid] >= num){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return ans == -1 ? 0 : m - ans;
}

void solve(){
    // n planks, 2 different colors
    // same color painted should form a sequence
    // m different paints, ith color -> ai no of planks

    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);

    for(ll i = 0; i < m; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll combinations = 0;
    for(ll i = 1; i <= n/2; i++){
        ll left = i, right = n - i;

        // find the no of colors >= left , also >= right
        ll for_left = bs(a, m, left);
        ll for_right = bs(a, m, right);

        ll curr_combi = for_left * for_right - for_right;

        if(left != right) curr_combi *= 2;
        combinations += curr_combi;
    }

    cout << combinations << endl;
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