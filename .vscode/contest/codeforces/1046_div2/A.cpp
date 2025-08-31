#include <bits/stdc++.h>
using namespace std;

void solve(){
    /*
    int A, B, C, D, a, b, c, d;
    cin >> a >> b >> c >> d;

    // check for first half
    if(a >= b && ((a / 2 + a % 2) - 1) > b){
        cout << "NO" << endl;
        return ;
    }
    if(b >= a && ((b / 2 + b % 2) - 1) > a){
        cout << "NO" << endl;
        return ;
    }

    // now check for second half individually
    c -= a, d -= b;
    if(c >= d && ((c / 2 + c % 2) - 1) > d){
        cout << "NO" << endl;
        return ;
    }
    if(d >= c && ((d / 2 + d % 2) - 1) > c){
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;
    return ;
    */

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    c -= a, d -= b;
    // Therefore, the scores x:y in a single half are possible, if and only if max(x,y)≤2⋅min(x,y)+2
    if((max(a, b) > 2*min(a, b) + 2) || (max(c, d) > 2*min(c, d) + 2)){
        cout << "NO" << endl;
        return ;
    }
    
    cout << "YES" << endl;
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