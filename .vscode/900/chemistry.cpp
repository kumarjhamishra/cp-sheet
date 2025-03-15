#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for(ll i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }

    if((n - k) % 2 == 1) k += 1;

    for(int i = 0; i < 26; i++){
        if(freq[i] == 0 || freq[i] % 2 == 0) continue;
        
        // frequency is odd of char
        if(k == 0){
            cout << "NO" << endl;
            return ;
        }

        k--;
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