#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    // base case
    // from (a, b) we can't reach to (c, d) if (c, d) is on same line and right or if (c, d) lies below (a, b)
    if((a < c && b == d) || (b > d)){
        cout << -1 << endl;
        return ;
    }

    // when points are same
    if(a == c && b == d){
        cout << 0 << endl;
        return ;
    }

    ll moves = d - b;
    if(c > a + moves){
        cout << -1 << endl;
        return ;
    }
    moves += (a + moves - c);
    cout << moves << endl;
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