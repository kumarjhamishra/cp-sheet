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
    int n;
    cin >> n;

    string s;
    cin >> s;

    // in subsequence p remove all the 1's 
    // remaining all the 0's will automatically be in palindrome
    vi ones;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') continue;

        ones.push_back(i+1);
    }

    cout << ones.size() << endl;
    if(ones.size() > 0){
        for(int idx : ones){
            cout << idx << " ";
        }
        cout << endl;
    }
    
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