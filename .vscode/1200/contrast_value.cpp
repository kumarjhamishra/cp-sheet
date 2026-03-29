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

    // remove adjance duplicates
    vi a_unique;
    a_unique.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] != a_unique.back()) a_unique.push_back(a[i]);
    }

    if(a_unique.size() <= 2){
        cout << a_unique.size() << endl;
        return ;
    }

    // now count the peaks and dips in between the first and last element
    int dir_change = 0;
    for(int i = 1; i < a_unique.size()-1; i++){
        if((a_unique[i] > a_unique[i-1] && a_unique[i] > a_unique[i+1]) || (a_unique[i] < a_unique[i-1] && a_unique[i] < a_unique[i+1])){
            dir_change++;
        }
    }

    cout << dir_change + 2 << endl;
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