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

void solve()
{
    /*
    int n;
    cin >> n;
    ll m = n * (n - 1) / 2;

    
    map<int, int> mp;
    for(int i = 0; i < m; i++){
        int ele;
        cin >> ele;
        mp[ele]++;
    }

    priority_queue<pii> pq;
    for(auto i : mp){
        pq.push({i.first, i.second});
    }

    vi a(n+1);
    int i = n-1; // second last element
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        a[i] = node.first;
        // cout << "n-i: " << n - i << endl;
        node.second -= (n - i);
        //cout << "node.second: " << node.second << endl;
        if(node.second > 0) pq.push({node.first, node.second});
        i--;
        //cout << "hello" << endl;
    }
    // fill last element
    a[n] = a[n-1];
    // cout << "ans" << endl;
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    */

    // approach 2
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;
    vi b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());
    for(int i = 0; i < m; i += --n) cout << b[i] << " ";
    cout << (int)1e9 << endl;
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