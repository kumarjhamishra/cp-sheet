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

const int mod = 1e9+7;

int calculateGCD(int a, int b){
    if(b == 0) return a;

    return calculateGCD(b, a%b);
}

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto &i : a) cin >> i;

    // base case
    if(n == 1){
        cout << 0 << endl;
        return ;
    }

    int i = 0, j = n-1, x = 0;
    while(i <= j){
        x = calculateGCD(x, abs(a[i++] - a[j--]));
    }
    cout << x << endl;
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