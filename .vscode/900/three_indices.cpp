#include <bits/stdc++.h>
using namespace std;
// three_indices.cpp

void solve(){
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    int left_small = 0, mid_max = 1;
    for(int i = 2; i < n; i++){
        

        if(p[left_small] < p[mid_max] && p[mid_max] > p[i]){
            cout << "YES" << endl;
            cout << left_small+1 << " " << mid_max+1 << " " << i+1 << endl;
            return ;
        }

        if(p[i] < p[left_small]){
            
        }

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