#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n, r, b;
    cin >> n >> r >> b;

    string ans = "", red = "";
    int baseWins = r/(b+1), extraWins = r % (b+1);
    red = string(baseWins+1, 'R');
    for(int i = 0; i < extraWins; i++){
        ans += red;
        ans.push_back('B');
    }
    red = string(baseWins, 'R');
    for(int i = extraWins; i < b; i++){
        ans += red;
        ans.push_back('B');
    }
    ans += red;
    cout << ans << endl;
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