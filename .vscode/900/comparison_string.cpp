#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    // we need to find the longest consecutive length 
    ll longest_length = 0, length = 1;
    for(ll i = 1; i < n; i++){
        if(s[i] == s[i-1]) length++;
        else{
            longest_length = max(longest_length, length);
            length = 1;
        }
    }
    longest_length = max(longest_length, length);

    cout << longest_length + 1 << endl;
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