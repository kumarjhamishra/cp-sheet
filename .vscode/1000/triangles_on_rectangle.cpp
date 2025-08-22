#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int w, h;
    cin >> w >> h;

    ll area = LLONG_MIN; 
    for(int i = 0; i < 4; i++){
        int k;
        cin >> k;
        ll b1 = -1, b2 = -1;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            if(b1 == -1) b1 = x;
            else b2 = x;
        }
        if(i < 2) area = max(area, (b2 - b1) * h);
        else area = max(area, (b2 - b1) * w);
    }

    cout << area << endl;
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