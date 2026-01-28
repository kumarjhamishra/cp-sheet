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

    vi w(n);
    for(auto &i : w) cin >> i;

    int i = 0, pre_i = -1, j = n-1, pre_j = n, maxCandies = 0;
    ll lsum = 0ll, rsum = 0ll;
    while(i < j){
        if(i > pre_i) lsum += w[i];
        if(j < pre_j) rsum += w[j];

        if(lsum == rsum){
            maxCandies = (i + 1) + (n - j);
            pre_i = i, pre_j = j;
            i++, j--;
        }
        else if(lsum < rsum){
            pre_i = i, pre_j = j;
            i++;
        }
        else{
            pre_j = j, pre_i = i;
            j--;
        }
    }

    cout << maxCandies << endl;
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