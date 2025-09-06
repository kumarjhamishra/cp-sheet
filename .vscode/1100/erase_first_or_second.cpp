#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    // the total n-i length distinct strings = total distinct char's till the ith index
    // abacd
    
    vll freq(26, 0ll);
    ll distinctCount = 0, totalDistinctStrings = 0;
    for(int i = 0; i < n; i++){
        if(++freq[s[i] - 'a'] == 1){
            distinctCount++;
        }
        totalDistinctStrings += distinctCount;
    }
    cout << totalDistinctStrings << endl; 
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