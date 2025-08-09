#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n;
    cin >> n;

    vi s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    // base case - n = 1 -> shuffling not possible
    if(n == 1){
        cout << -1 << endl;
        return ;
    }

    // if any number is unique - impossible to make a valid shuffling
    vi ans(n);
    for(int i = 0; i < n; ){
        int j = i;
        while(j+1 < n && s[j+1] == s[i]) j++;

        // case of unique element
        if(i == j){
            cout << -1 << endl;
            return ;
        }

        ans[j] = (i+1);
        for(int k = i; k < j; k++) ans[k] = (k+1+1);

        i = j + 1;
    }

    for(int i : ans) cout << i << " ";
    cout << endl;
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