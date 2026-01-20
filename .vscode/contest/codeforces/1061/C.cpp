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
    int n, k;
    cin >> n >> k;

    vi a(n), mp(n+1), prefix(n+1);
    // mp will store the count of each num from 1 to n bcoz 1<= a_i <= n
    // prefix will store the count of num's from 1 to i
    for(auto &i : a){
        cin >> i;
        mp[i]++;
    } 

    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + mp[i];

    /*
    g will be valid if:
    (x -> elements of a)
    count(x >= 4g) + count(x = g) + count(x = 2g) + count(x = 3g) >= n-k
    bcoz at max we can erase k elements
    */
    int ans = 1;
    for(int g = n; g > 1; g--){
        // prefix[4*g] will store the count of elements from 1 to 4g
        int count = n - prefix[min(4*g-1, n)];
        count += mp[g];
        if(2*g <= n) count += mp[2*g];
        if(3*g <= n) count += mp[3*g];

        if(count >= n-k){
            ans = g;
            break;
        }
    }
    cout << ans << endl;
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