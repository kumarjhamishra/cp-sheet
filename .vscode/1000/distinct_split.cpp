#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

void solve(){
    int n;
    cin >> n;

    vi a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vi a_pre(n, 1), b_pre(n, 1);
    // also calculate the max length of subarray for each digit in both a and b
    int maxiA = *max_element(a.begin(), a.end()), maxiB = *max_element(b.begin(), b.end()), maxi = max(maxiA, maxiB) + 1;
    vi maxLenInA(maxi, 0), maxLenInB(maxi, 0);
    maxLenInA[a[n-1]] = 1, maxLenInB[b[n-1]] = 1;
    for(int i = n-2; i >= 0; i--){
        if(a[i] == a[i+1]){
            a_pre[i] += a_pre[i+1];
        }
        if(b[i] == b[i+1]){
            b_pre[i] += b_pre[i+1];
        }
        maxLenInA[a[i]] = max(maxLenInA[a[i]], a_pre[i]);
        maxLenInB[b[i]] = max(maxLenInB[b[i]], b_pre[i]);
    }

    // cout << "printing max sub array length for each digit in a and b" << endl;
    // for(int i = 0; i < 10; i++){
    //     cout << maxLenInA[i] << " " << maxLenInB[i] << endl;
    // }

    int maxLen = 1;
    for(int i = 0; i < maxi; i++){
        //if(maxLenInA[i] == 0 || maxLenInB[i] == 0) continue;

        maxLen = max(maxLen, maxLenInA[i] + maxLenInB[i]);
    }

    cout << maxLen << endl;
    
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