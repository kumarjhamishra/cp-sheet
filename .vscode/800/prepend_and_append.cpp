#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll i = 0, j = n-1;
    while(i < j){
        if(s[i] == s[j]){
            break;
        }
        i++, j--;
    }
    
    cout << j - i + 1 << endl;
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