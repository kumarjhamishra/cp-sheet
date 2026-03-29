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

void solve(){
    int n, k;
    cin >> n >> k;

    vi c(n);
    for(auto &i : c) cin >> i;

    // lengths of two maximum steps between plans of that color
    vi last(k, -1), max_step(k), max2_step(k);
    for(int i = 0; i < n; i++){
        int step = i - last[c[i] - 1];
        if(step > max_step[c[i]  - 1]){
            max2_step[c[i] - 1] = max_step[c[i] - 1];
            max_step[c[i] - 1] = step;
        }
        else if(step > max2_step[c[i] - 1]){
            max2_step[c[i] - 1] = step;
        }
        last[c[i] - 1] = i;
    }

    for(int i = 0; i < k; i++){
        int step = n - last[i];
        if(step > max_step[i]){
            max2_step[i] = max_step[i];
            max_step[i] = step;
        }
        else if(step > max2_step[i]){
            max2_step[i] = step;
        }
    }

    int ans = 1e9;
    for(int i = 0; i < k; i++){
        ans = min(ans, max((max_step[i]+1)/2, max2_step[i]));
    }
    cout << ans - 1 << endl;
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