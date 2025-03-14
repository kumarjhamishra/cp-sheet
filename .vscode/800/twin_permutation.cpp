#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b(n);
    // rather than <= solving the question for just =

    // so trying to have a permuation so that ai + bi = ai+1 + bi+1 = ai+2 + bi+2
    for(int i = 0; i < n; i++){
        b[i] = n + 1 - a[i];
        cout << b[i] << " ";
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