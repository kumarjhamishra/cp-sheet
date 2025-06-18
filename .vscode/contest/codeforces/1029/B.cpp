#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin >> n;

    vector<int> p(n);

    int ele = 1;
    for(int i = 0; i < n/2; i++){
        p[i] = ele;
        ele++;
        p[n-i-1] = ele;
        ele++;
    }
    if(n % 2 == 1) p[n/2] = ele;

    for(int i : p){
        cout << i << " ";
    }
    cout << endl;
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