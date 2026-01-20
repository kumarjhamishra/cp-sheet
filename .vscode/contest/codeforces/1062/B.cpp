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
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vi freq(26, 0);

    for(char ch : s) freq[ch - 'a']++;
    for(char ch : t) freq[ch - 'a']--;

    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
    return ;
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