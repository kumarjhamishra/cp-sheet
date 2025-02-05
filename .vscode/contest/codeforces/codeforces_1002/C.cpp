#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // from the end side of each row we need to calculate that how many rows contains how much continous 1's
    vector<int> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(0);
        for(int j = n-1; j >= 0; j--){
            if(a[i][j] != 1) break;
            arr.back()++;
        }
    }

    // sort the count of each rows having continous 1's from end side
    sort(arr.begin(), arr.end());

    int idx = 0, MEX = 0;
    while(idx < n){
        // find that number in arr whose value >= MEX value required
        idx = lower_bound(arr.begin()+idx, arr.end(), MEX) - arr.begin();
        if(idx == n){
            cout << MEX << endl;
            return ;
        } 
        MEX++;
        idx++;
    }

    cout << MEX << endl;
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