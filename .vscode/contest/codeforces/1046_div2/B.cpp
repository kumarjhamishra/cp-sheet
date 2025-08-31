#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // max consecutive length of 1's < k -> for a possible permutation
    int maxLen = INT_MIN, currLen = 0;
    for(int i = 0; i < n; ){
        if(s[i] == '0'){
            i++;
        }
        else{
            currLen = 0;
            int j = i;
            for(; j < n; j++){
                if(s[j] != '1') break;
                currLen++;
            }
            maxLen = max(maxLen, currLen);
            i = j;
        }
    }

    if(maxLen >= k){
        cout << "NO" << endl;
        return ;
    }

    // answer is possible
    int num = n;
    vector<int> p(n);
    // first fill the 0's
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            p[i] = num--;
        }
    }

    // now fill 1's
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            p[i] = num--;
        }
    }

    cout << "YES" << endl;
    for(auto &i : p) cout << i << " ";
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