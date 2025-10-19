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
    int a, b;
    cin >> a >> b;

    // calculate the x_res needed 
    int x_res = a ^ b;

    // base case
    if(x_res == 0){
        cout << 0 << endl;
        return ;
    }

    // find MSB position of a and x_res
    int msb_a = 31 - __builtin_clz(a);
    int msb_x = 31 - __builtin_clz(x_res);

    if(msb_x > msb_a){
        cout << -1 << endl;
        return;
    }

    // print the number of operations required
    int operations = __builtin_popcount(x_res);
    cout << operations << endl;
    // now print these numbers
    for(int i = 0; i <= 31; i++){
        if(x_res & (1 << i)){
            int singleBit = (1 << i);
            cout << singleBit << " ";
        }
    }
    cout << endl;
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