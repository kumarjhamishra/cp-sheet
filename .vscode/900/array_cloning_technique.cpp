#include <bits/stdc++.h>
using namespace std;

// array_cloning_technique.cpp

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    // here when used unordered_map it gave TLE and when used map it passed
    map<int, int> freq;
    // keep track of max freq
    int maxFreq = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
        maxFreq = max(maxFreq, freq[a[i]]);
    }

    // if maxFreq is equal to n, then all elements are same
    if(maxFreq == n){
        cout << 0 << endl;
        return ;
    }

    int moves = 0, remainingElements = n - maxFreq;
    while(maxFreq < n){
        int newElements = min(remainingElements, maxFreq);
        moves += (1 + newElements);
        remainingElements -= newElements;
        maxFreq += newElements;
    }

    cout << moves << endl;
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