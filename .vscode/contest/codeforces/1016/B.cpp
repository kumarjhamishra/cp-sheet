#include <bits/stdc++.h>
using namespace std;

void solve(){
    string n;
    cin >> n;

    int size_n = n.size();

    // base case
    if(size_n == 1){
        cout << 0 << endl;
        return ;
    }

    // for each digit we want to store how many digits are in it's suffix
    vector<int> suffix_zeros(size_n, 0);
    if(n[size_n-1] == '0') suffix_zeros[size_n-1] = 1;
    for(int i = size_n-2; i >= 0; i--){
        suffix_zeros[i] = suffix_zeros[i+1];
        if(n[i] == '0') suffix_zeros[i] += 1;
    }

    // case of no zeroes are present in the digit
    if(suffix_zeros[0] == 0){
        cout << size_n - 1 << endl;
        return ;
    }

    int i = size_n-1;
    while(i >= 0 && n[i] == '0'){
        i--;
    }

    int minimumMoves = 2*suffix_zeros[i] - suffix_zeros[0] + i;
    cout << minimumMoves << endl;
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