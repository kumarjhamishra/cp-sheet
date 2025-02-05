#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    if(k == n){
        for(int ik = 1; ik <= n; ik++){
            if(ik % 2 == 1) continue;

            if(a[ik-1] != ik/2){
                cout << ik/2 << endl;
                return ;
            }
        }

        cout << k/2 + 1 << endl;
        return ;
    }

    // windowSize >= 2
    int windowEnd = n-1 - (k - 2);
    int countOf1 = 0;
    for(int i = 1; i <= windowEnd; i++){
        if(a[i] == 1) countOf1++;
    }

    cout << (countOf1 == windowEnd ? 2 : 1) << endl;
    return ;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}