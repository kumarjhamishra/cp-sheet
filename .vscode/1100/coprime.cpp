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

vvi pairs(1001);

void solve(){
    int n;
    cin >> n;

    // store the maximum index for each number in the given array
    vi index(1001, 0);

    for(int i = 1; i <= n; i++){
        int ele;
        cin >> ele;
        index[ele] = i;
    }

    int sum = -1;
    for(int e1 = 1; e1 <= 1000; e1++){
        // element not present in original array
        if(index[e1] == 0) continue;

        for(int e2 : pairs[e1]){
            if(index[e2] == 0) continue;

            sum = max(sum, index[e1] + index[e2]);
        }
    }

    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            if(__gcd(i, j) == 1) pairs[i].push_back(j);
        }
    }

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}