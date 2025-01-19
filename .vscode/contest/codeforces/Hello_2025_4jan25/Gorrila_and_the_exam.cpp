#include <bits/stdc++.h>


using namespace std;
using p = pair<int, int>;

int solve(vector<int> &arr, int &n, int k){
    /*
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
    */

    // more optimised writing
    sort(arr.begin(), arr.end());
    // count the freq of each unique no in cnt arr
    // size of the cnt arr is no of unique elements, and the cnt[i] is the freq of each unique no
    vector<int> cnt;
    cnt.push_back(1);
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]){
            cnt.back()++;
        }
        else{
            cnt.push_back(1);
        }
    }

    // sort the cnt to get the minimum freq and maximum frequency
    sort(cnt.begin(),  cnt.end());
    int m = cnt.size();
    for(int i = 0; i < m-1; i++){
        // when k is finished
        if(cnt[i] > k) return m-i;
        k -= cnt[i];
    }

    //comes here means all small no's are changed in the largest no so return 1
    return 1;

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