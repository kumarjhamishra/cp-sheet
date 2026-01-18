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

    vi a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    /*
    // for each i(including i) store the length of non decreasing subarray ending at i
    vector<pib> pre(n, {1, false}); // {length, isDifferent} element of b_i from a_i
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) pre[i].second = true;
        if(i > 0 && b[i-1] <= b[i]){
            pre[i].first += pre[i-1].first;
            pre[i].second |= pre[i-1].second;
        }
    }

    int l = -1, r = -1, maxLen = INT_MIN;
    for(int i = 0; i < n; i++){
        if(pre[i].first > maxLen && pre[i].second){
            maxLen = pre[i].first;
            r = i;
            l = r - maxLen + 1;
        }
    }

    cout << l + 1 << " " << r + 1 << endl;
    return ;
    */



    // approach 2 - without taking space
    int diffl = -1, diffr = -1;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            diffr = i;
            if(diffl == -1) diffl = i;
        }
    }

    while(diffl > 0 && b[diffl-1] <= b[diffl]) diffl--;
    while(diffr < n-1 && b[diffr] <= b[diffr+1]) diffr++;

    cout << diffl + 1 << " " << diffr + 1 << endl;
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