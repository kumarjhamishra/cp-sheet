#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

//#define pb push_back

void solve(){
    int n, k;
    cin >> n >> k; // k -> k cells from where if we start we will surely find the escape

    // total trap cells
    k = n*n - k;
    if(k == 1){
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;
    
    // for k trap cells creating a loop in the first row
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(k){
                if(i == 0 && j == 0) cout << "R" ;
                else if(i == 0) cout << "L";
                else cout << "U";
                k--;
            }
            else cout << "D"; // non trapping cell
        }
        cout << endl;
    }
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