#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;


    // we will store the n-1 maximum 2nd element of each array
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        int m; 
        cin >> m;
        vector<int> a(m);

        for(int j = 0; j < m; j++){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        mini = min(mini, a[0]);
        minHeap.push(a[1]);
    }

    // currently the min heap store the n elements
    minHeap.pop();


    ll maxBeauty = 1ll * mini;
    while(!minHeap.empty()){
        maxBeauty += 1ll * minHeap.top();
        minHeap.pop();
    }

    cout << maxBeauty << endl;


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