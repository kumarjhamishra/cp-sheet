#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>


using namespace std;
using p = pair<int, int>;

int solve(vector<int> &arr, int &n, int k){
    // base case
    if(n == 1) return 1;

    unordered_map<int, int> freq;
    for(int i : arr){
        freq[i]++;
    }

    int ans = freq.size();

    if(k == 0) return ans;

    priority_queue<p, vector<p>, greater<p>> minHeap; // {freq, number}
    for(auto i : freq){
        minHeap.push({i.second, i.first});
    }

    while(k > 0){
        p topa = minHeap.top();
        minHeap.pop();
        int freq = topa.first;
        int num = topa.second;

        if(k >= freq){
            ans--;
            k -= freq;
        }
        else break;
    }

    return max(1, ans);

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<solve(arr, n, k)<<endl;;
    }
    return 0;
}