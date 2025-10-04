#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

void solve(){
    int n;
    cin >> n;
    vi p(n);

    for(auto &i : p) cin >> i;

    // from the highest element to the both side the array should be decreasing 
    // to make all the elements 0 in the last

    int idx = -1;
    for(int i = 0; i < n; i++){
        if(p[i] == n){
            idx = i;
            break;
        }
    }

    // now check to it's both sides
    
    // left side check
    for(int i = idx-1; i >= 0; i--){
        if(p[i] > p[i+1]){
            cout << "NO" << endl;
            return ;
        }
    }

    // right side check
    for(int i = idx+1; i < n; i++){
        if(p[i] > p[i-1]){
            cout << "NO" << endl;
            return ;
        }
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