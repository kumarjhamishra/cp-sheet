#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m));
    int totalSum = 0, absoluteMinimumValue = 100, totalNegatives = 0, negativeSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            totalSum += a[i][j];
            absoluteMinimumValue = min(absoluteMinimumValue, abs(a[i][j]));
            if(a[i][j] < 0){
                totalNegatives++;
                negativeSum += a[i][j];
            }
        }
    }

    
    totalSum += negativeSum * -2;
    if(totalNegatives % 2) totalSum -= absoluteMinimumValue * 2;

    cout << totalSum << endl;
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