#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin >> n >> k;
    string stripe;
    cin >> stripe;

    int minimumRecolor = 0, currentWhites = 0;
    for(int i = 0; i < k; i++){
        if(stripe[i] == 'W') currentWhites++;
    }
    minimumRecolor = currentWhites;

    for(int i = k; i < n; i++){
        if(stripe[i] == 'W') currentWhites++;
        if(stripe[i - k] == 'W') currentWhites--;

        minimumRecolor = min(minimumRecolor, currentWhites);
    }
    
    cout << minimumRecolor << endl;
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