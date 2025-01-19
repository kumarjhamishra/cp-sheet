#include <bits/stdc++.h>

using namespace std;
using ll = long long;


vector<ll> solve(ll &l, ll &r){
    if(r-l+1 == 3) return {l, l+1, l+2};

    // our main is that at every bit position if it's possible then maintain at least one no diff like 1, 0, 1
    ll a, b, c;
    ll ans = 0;
    // from that bit position where l and r has diff bit we will try to maintain 
    // a as 1 0 0 0 0 and b as 0 1 1 1 1 for max or result and take c anything
    // as that will effect not the result
    for(int i = 30; i >= 0; i--){
        ll b1 = 0, b2 = 0;
        // get the bit from no l
        if(l & (1ll << i)){
            b1 = 1;
        }
        // get the bit from no r
        if(r & (1ll << i)){
            b2 = 1;
        }

        // if both l and r have same curr bit directly use it from a, b and c
        // as changing that bit will take us out of range from [l, r]
        if(b1 == b2){
            ans += b1 * (1ll << i);
        }
        // they got the diff bit
        // from this bit set a as 1 0 0 0  and b as 0 1 1 1 
        else{
            a = ans + (1ll << i);
            b = a - 1;
            break;
        }
    }

    // from [l, r] take anything which is not a and b as c that will not affect the result
    for(ll i = l; i <= r; i++){
        if(i != a && i != b){
            c = i;
            break;
        }
    }

    return {a, b, c};

}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll l, r;
        cin>>l>>r;
        vector<ll> ans = solve(l, r);
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    }
    return 0;
}