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
    /*
    It tells us, if a book has difficulty rating y
    , and x|y≠x
    , Tenzing will never read this book because it will change a 0
    bit in x
    to 1
    .

    We called a number y
    valid if x|y=x
    . For each sequence, we can find a longest prefix of it such that all numbers in this prefix are valid. Find the bitwise OR of the three prefix and check whether it equals to x
    .
    */
    int n, x;
    cin >> n >> x;
    vvi abc(3, vi(n));
    int orResult = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> abc[i][j];
        }
        for(int j = 0; j < n; j++){
            if((x | abc[i][j]) != x) break;
            orResult |= abc[i][j];
        }
    }

    // base case - when required knowledge is 0
    // if(x == 0){
    //     cout << "YES" << endl;
    //     return ;
    // }

    if(orResult == x) cout << "YES" << endl;
    else cout << "NO" << endl;
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