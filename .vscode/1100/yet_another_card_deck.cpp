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
    int n, q;
    cin >> n >> q;
    //cout << "n: " << n << " q: " << q << endl;
    // store the first left most index where the number is available
    vi posn(51, -1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        //cout << "x: " << x << endl;
        if(posn[x] == -1){
            posn[x] = i;
            //cout << "x: " << x << " posn: " << posn[x] << endl;
        }
    }

    vi t(q);
    for(auto &i : t) cin >> i;

    // cout << "initial idx" << endl;
    // for(int i = 1; i <= 50; i++){
    //     if(posn[i] == -1) continue;
    //     cout << "i : " << i << " posn: " << posn[i] << endl;
    // }

    for(int j : t){
        cout << posn[j] << " ";
        for(int i = 1; i <= 50; i++){
            if(posn[i] != -1 && posn[i] < posn[j]) posn[i] += 1;
        }
        posn[j] = 1;
    }
    cout << endl;
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    // int t;
    // cin >> t;
    // while(t--){
    // }

    return 0;
}