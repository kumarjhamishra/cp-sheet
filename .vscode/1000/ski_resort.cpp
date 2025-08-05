#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

void solve(){
    int n, k, q;
    cin >> n >> k >> q;

    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int i = 0;
    ll ways = 0;
    while(i < n){
        int j = i;
        while(j < n && a[j] <= q){
            j++;
        }

        // this range j - i >= k
        if(j - i >= k){
            for(int s = i; s < j; s++){
                int e = s + k - 1;
                if(e < j){
                    ways += 1ll * (j - e);
                }
                else break;
            }
        }

        i = j+1;
    }

    cout << ways << endl;
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