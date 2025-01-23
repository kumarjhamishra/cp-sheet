#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cards(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cards[i][j];
        }
    }

    // sort the cards for each cow and the diff between 2 adjcent cards must = n for a valid possible arrangement
    for(int i = 0; i < n; i++){
        sort(cards[i].begin(), cards[i].end());
        for(int j = 1; j < m; j++){
            if(cards[i][j] - cards[i][j-1] != n){
                cout << -1 << endl;
                return ;
            }
        }
    }

    // if came here means a valid arrangement is possible
    vector<p> arrangment(n);
    for(int i = 0; i < n; i++){
        arrangment[i] = {cards[i][0], i};
    }

    sort(arrangment.begin(), arrangment.end());

    //cout << "ans" << endl;
    for(auto i : arrangment){
        cout << i.second + 1 << " ";
    }

    cout << endl;
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