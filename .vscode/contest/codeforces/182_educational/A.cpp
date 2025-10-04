#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto &i : a) cin >> i;

    vi prefix(n, 0);
    prefix[0] = a[0];
    for(int i = 1; i < n; i++){
        prefix[i] = a[i] + prefix[i-1];
    }

    for(int i = 1; i <= n-1; i++){
        for(int j = i; j <= n-1; j++){
            int s1 = prefix[i-1];
            int s2 = prefix[j] - s1;
            int s3 = prefix[n-1] - s2 - s1;
            if(s1 % 3 != s2 % 3 && s1 % 3 != s3 % 3 && s2 % 3 != s3 % 3){
                cout << i << " " << j+1 << endl;
                return ;
            }
            else if(s1 % 3 == s2 % 3 && s1 % 3 == s3 % 3){
                cout << i << " " << j+1 << endl;
                return ;
            }
        }
    }

    cout << 0 << " " << 0 << endl;
    return;
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