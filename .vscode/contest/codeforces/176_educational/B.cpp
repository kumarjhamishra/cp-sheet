#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    // we need to store the maximum k+1 elements of the array
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        minHeap.push(val);
        if(minHeap.size() > k + 1) minHeap.pop();
    }

    int sum = 0;
    while(!minHeap.empty()){
        sum += minHeap.top();
        minHeap.pop();
    }

    cout << sum << endl;
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