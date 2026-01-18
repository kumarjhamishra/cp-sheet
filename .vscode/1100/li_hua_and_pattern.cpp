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
    int n, k;
    cin >> n >> k;

    vvi a(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // count differences
    int k_min = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != a[n-1-i][n-1-j]) k_min++;
        }
    }
    k_min /= 2;

    if(k_min > k){
        cout << "NO" << endl;
        return ;
    }

    /*
    If n is odd: The answer is always "YES". Why? Because you have a 
    center cell (n/2, n/2) that is its own $180^\circ$ rotation. You can 
    waste any number of leftover operations by just flipping this center 
    cell back and forth. If k - k_min is 5, you flip it 5 times. The 
    final state is still symmetric.
    */

    /*
    If n is even: The answer is "YES" if and only if (k - k_min) is even. 
    Why? Because there is no center cell. Every cell (i, j) is paired with
    (n-1-i, n-1-j). To "waste" operations without changing the final 
    symmetry, you must flip a cell and then flip it back (2 ops) or flip 
    a pair (i,j) and (n-1-i, n-1-j) (2 ops). You 
    can only waste operations in pairs. Therefore, k - k_min must be even.
    */


    // n is even and left over actions not in pair
    if(!(n & 1) && (k - k_min) & 1){
        cout << "NO" << endl;
        return ;
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