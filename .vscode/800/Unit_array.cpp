#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    int negatives = 0, positives = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == -1) negatives++;
        else positives++;
    }

    // base case
    if(positives >= negatives && negatives % 2 == 0){
        cout << 0 << endl;
        return ;
    }

    // sum condition is satisfied but not the product condition
    if(positives >= negatives){
        cout << 1 << endl;
        return ;
    }

    // sum condition is not even satisfied
    int new_negatives = (positives + negatives) / 2;
    if(new_negatives % 2 != 0) new_negatives -= 1;

    cout << negatives - new_negatives << endl;
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