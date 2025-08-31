#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAXN = 2e5+1;
vi a(MAXN), dp(MAXN, 0);
vector<deque<int>> dq(MAXN); // array of deque
void solve(){
    

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) dq[i].clear();
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        // push the index of element a[i] as i 
        dq[a[i]].push_back(i);

        // maintain the count of a[i] element as a[i] in the dq
        if(dq[a[i]].size() > a[i]) dq[a[i]].pop_front();

        // if the current element completes the count of a[i] to a[i] then can take the
        // current element a[i] in the subsequence as a block ending at a[i]
        // else can't and the answer for the previous index will be carry forward

        if(dq[a[i]].size() == a[i]){
            dp[i] = max(dp[i-1], dp[dq[a[i]].front() - 1] + a[i]);
        }
        else dp[i] = dp[i-1];
    }
    cout << dp[n] << endl;
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