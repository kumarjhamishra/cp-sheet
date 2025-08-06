#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    // store the next nearest index of green light for each index
    vi nextGreen(2*n, -1);
    s += s;
    if(s[2*n-1] == 'g') nextGreen[2*n-1] = 2*n-1;
    for(int i = 2*n-2; i >= 0; i--){
        if(s[i] == 'g') nextGreen[i] = i;
        else nextGreen[i] = nextGreen[i+1];
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        if(s[i] == c){
            ans = max(ans, nextGreen[i] - i);
        }
    }

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