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
    // to be a perfectly balanced string it should made of smallest repeating unit of the string should have all distinct characters
    string s;
    cin >> s;

    // total unique characters
    vb present(26, false);
    int k = 0;
    for(char ch : s){
        if(!present[ch - 'a']){
            k++;
            present[ch - 'a'] = true;
        }
    }

    // let's say the total unique characters in the string is k, then for every i the char at i+k should be same as i
    for(int i = 0; i < s.size() - k; i++){
        if(s[i] != s[i+k]){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
    return ;

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