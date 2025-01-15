#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<ll>> a(n, vector<ll>(m));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    // we need the row sums and column sums
    vector<ll> rowSums(n, 0), columnSums(m, 0);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            rowSums[i] += a[i][j];
            columnSums[j] += a[i][j];
        }
    }


    ll stringSize = s.size(), idx = 0, row = 0, col = 0;
    while(idx < stringSize){
        if(s[idx] == 'D'){
            // then the path will not come again to this row
            // so use the row sum for value
            a[row][col] = -rowSums[row];

            // now make the sum of curr row to 0
            rowSums[row] = 0;
            // and update it's column sum with this cell value
            columnSums[col] += a[row][col];

            row++;

        }
        else{
            a[row][col] = -columnSums[col];
            columnSums[col] = 0;
            rowSums[row] += a[row][col];
            col++;
        }
        idx++;
    }

    // now handle the cell {n-1, m-1}
    //if(rowSums[n-1] != 0) a[row][col] = -rowSums[n-1];
    a[row][col] = -columnSums[m-1];

    //cout << "Printing a values" << endl;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

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