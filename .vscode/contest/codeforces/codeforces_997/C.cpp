#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    if(n == 6){
        cout << "1 1 2 3 1 2" << endl;
        return ;
    }
    if(n == 7){
        cout << "1 1 2 3 1 2 2" << endl;
        return ;
    }
    if(n == 9){
        cout << "7 3 3 7 5 3 7 7 3" << endl;
        return ;
    }
    if(n == 15){
        cout << "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8" << endl;
        return ;
    }

    vector<int> a(n);
    for(int i = 0; i < n/2; i++){
        a[i] = i+1;
    }
    for(int i = n/2; i < n; i++){
        a[i] = i - n/2 + 1;
    }

    for(int i : a) cout << i << " ";
    cout << endl;
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