#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
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
    string s;
    cin >> s;

    // ultimately we need to find the longest length of consecutive 1's maintaining the circular nature
    s = s + s;
    int currLen = 0, maxLen = 0;
    for(char c : s){
        currLen = c == '1' ? currLen+1 : 0;
        maxLen = max(maxLen, currLen);
    }

    // all 1's -> len = n*n
    if(maxLen == s.size()){
        cout << 1ll * (maxLen/2) * (maxLen/2) << endl;
        return ;
    }
    //cout << "maxLen: " << maxLen << endl;
    ll a = (maxLen + 1)/2, b = (maxLen + 2)/2;
    cout << a * b << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}