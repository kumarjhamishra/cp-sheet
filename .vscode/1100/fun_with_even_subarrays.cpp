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

    // we need to make all the elements equal to a[n-1]
    int target = a[n-1], x = 0, ops = 0, i = n-1;
    while(i >= 0){
        if(a[i] == target){
            // how many elements are equal to the last elment
            x++;
            i--;
        }
        else{
            // found element not equal to a[n-1]
            // now in one operation we can directly make subarray of x size in left equal to a[n-1]
            // with the x elements in left which is == a[n-1]
            ops++;
            i -= x;
            x *= 2;
        }
    }
    
    cout << ops << endl;
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