#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// mocha_and_math.cpp

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    int maxval = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxval &= a[i];
    }
    
    cout << maxval << endl;
    return ;

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