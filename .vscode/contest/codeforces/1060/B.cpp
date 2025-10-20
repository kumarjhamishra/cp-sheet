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

    vi a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    // 1 based indexing

    // first at all the even places places the maximum number from 1 into i
    int maxi = a[1];
    for(int i = 2; i <= n; i++){
        maxi = max(maxi, a[i]);
        if(i % 2 == 0) a[i] = maxi;
    }

    // cout << "printing a" << endl;
    // for(int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << endl;

    int operation2 = 0;
    for(int i = 1; i <= n; i += 2){
        if(i == 1 && a[i] >= a[i+1]){
            operation2 += (a[i] - a[i+1] + 1);
            //cout << "i: " << i << " op2: " << operation2 << endl;
        }
        else if(i == n && a[i] >= a[i-1]){
            operation2 += (a[i] - a[i-1] + 1);
            //cout << "i: " << i << " op2: " << operation2 << endl;
        }
        else if((i != 1 && i != n) && (a[i] >= a[i-1] || a[i] >= a[i+1])){
            operation2 += (a[i] - min(a[i-1], a[i+1]) + 1);
            //cout << "i: " << i << " op2: " << operation2 << endl;
        }
    }

    cout << operation2 << endl;
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