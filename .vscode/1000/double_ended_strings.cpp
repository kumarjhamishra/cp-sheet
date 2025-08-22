#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
//
void solve(){
    string a, b;
    cin >> a >> b;

    // set<string> st1, st2;
    // for(int i = 0; i < a.size(); i++){
    //     for(int j = i; j < a.size(); j++){
    //         string sub = a.substr(i, j-i+1);
    //         st1.insert(sub);
    //     }
    // }

    // for(int i = 0; i < b.size(); i++){
    //     for(int j = i; j < b.size(); j++){
    //         string sub = b.substr(i, j-i+1);
    //         st2.insert(sub);
    //     }
    // }
    
    // int minimumOperations = (int)(a.size() + b.size());
    // for(string s : st1){
    //     if(st2.find(s) != st2.end()){
    //         minimumOperations = min(minimumOperations, (int)a.size() + (int)b.size() - 2*(int)s.size());
    //     }
    // }

    // cout << minimumOperations << endl;





    // optimised approach
    int n = a.size(), m = b.size(), commonSubstringLength = 0;
    for(int len = 1; len <= min(n,m); len++){
        for(int i = 0; i + len <= n; i++){
            for(int j = 0; j + len <= m; j++){
                if(a.substr(i, len) == b.substr(j, len)) commonSubstringLength = max(commonSubstringLength, len);
            }
        }
    }

    cout << n + m - 2*commonSubstringLength << endl;
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