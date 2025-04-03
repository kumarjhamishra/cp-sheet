#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ab_balance.cpp

void solve(){
    string s;
    cin >> s;

    // if the first and last character of string are same
    // then the total number of "ab" and "ba" are same
    // otherwise make them same and it will equalize the total ab and ba

    if(s[0] == s.back()){
        cout << s << endl;
        return ;
    }
    s.back() = s[0];
    cout << s << endl;
    return ;

    // doing some randon stuff
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