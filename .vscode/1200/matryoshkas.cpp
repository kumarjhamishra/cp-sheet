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
    vi a(n);
    for(auto &i : a) cin >> i;

    sort(a.begin(), a.end());
    // store the elements as {ele, count}
    vector<pii> b;
    b.push_back({a[0], 1});
    for(int i = 1; i < n; i++){
        if(a[i] != b.back().first) b.push_back({a[i], 1});
        else b.back().second += 1;
    }

    int count = b[0].second;
    for(int i = 1; i < b.size(); i++){
        if(b[i].first == b[i-1].first + 1){
            count += (b[i].second - b[i-1].second > 0) ?  (b[i].second - b[i-1].second) : 0;
        }
        else{
            count += b[i].second;
        }
    }
    cout << count << endl;
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