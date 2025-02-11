#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    if(s == "us"){
        cout << "i" << endl;
        return ;
    }

    string ans = s.substr(0, s.size()-2);
    ans.push_back('i');
    cout << ans << endl;
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}