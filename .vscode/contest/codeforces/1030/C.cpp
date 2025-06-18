#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findOnes(ll num){
    ll cnt = 0;
    while(num){
        cnt += (num & 1);
        num = num >> 1;
    }
    return cnt;
}

void solve(){
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll currOne = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        currOne += findOnes(a[i]);
    }

    int totalCost = 0, bitPos = 0;
    while(bitPos < 64){
        // cost to make this bit posn 1 is
        ll cost = (1 << bitPos);
        bool breaked = false;
        for(ll i = 0; i < n; i++){
            // if for the a[i] the bit at bitPos is already 1 then no need to do anything
            int bit = (a[i] & (1 << bitPos));
            if(bit == 1) continue;

            cost -= a[i];
            if(k - cost >= 0){
                k -= cost;
                currOne++;
                a[i] = (a[i] | (1 << bitPos));
            }
            else{
                breaked = true;
                break;
            }
        }

        if(breaked){
            break;
        }

        bitPos++;
    }

    cout << "ans: " << currOne << endl;
    
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