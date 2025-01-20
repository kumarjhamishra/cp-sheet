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

    vector<p> rowSort;
    for(int i = 0; i < n; i++){
        rowSort.push_back({cards[i][0], i});
    }

    sort(rowSort.begin(), rowSort.end());

    
    vector<vector<int>> sortCards;
    vector<int> order;
    for(int i = 0; i < n; i++){
        int row = rowSort[i].second;
        sortCards.push_back(cards[row]);
        order.push_back(row+1);
    }

    bool check = true;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(sortCards[i][j] < sortCards[i-1][j]){
                check = false;
                break;
            }
        }
    }

    //cout << " ans " << endl;
    if(!check){
        cout << -1 << endl;
        return ;
    }

    check = true;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if(sortCards[i][j] < sortCards[i][j-1]){
                check = false;
                break;
            }
        }
    }

    if(!check){
        cout << -1 << endl;
        return ;
    }

    check = true;
    for(int j = 1; j < m; j++){
        if(sortCards[0][j] < sortCards[n-1][j-1]){
            check = false;
            break;
        }
    }

    if(!check){
        cout << -1 << endl;
        return ;
    }

    for(int i : order) cout << i << " ";
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