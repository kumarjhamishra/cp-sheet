#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// strange_partition.cpp

void solve(){
    // the maximum beuaty will be for the original array and the minimum beauty will be for the sum of a[i] over all i

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    ll sum = 0, maximumBeauty = 0, minimumBeauty = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        maximumBeauty += ceil((double)a[i] / x);
    }

    minimumBeauty = ceil((ld)sum / x);
    cout << minimumBeauty << " " << maximumBeauty << endl;
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