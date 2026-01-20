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

    vi a(n);
    for(auto &i : a) cin >> i;

    // only if the list contains all the even's or all the odd's element 
    // then only list can't be sorted in proper manner

    int odds = 0, evens = 0;
    for(int i : a){
        if(i % 2) odds++;
        else evens++;
    }

    if(odds != n && evens != n){
        sort(a.begin(), a.end());
    }

    for(int i : a) cout << i << " ";
    cout << endl;
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