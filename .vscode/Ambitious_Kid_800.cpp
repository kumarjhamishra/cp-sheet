// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &arr, int &n){
    int dist_from_zero = INT_MAX;
    
    for(int i = 0; i < n; i++){
        dist_from_zero = min(dist_from_zero, abs(arr[i]));
    }
    
    return dist_from_zero;
}

int main() {
    // int t;
    // cin>>t;
    // vector<int> ans;
    // while(t--){
    //     vector<vector<char>> arr(10, vector<char>(10));
    //     for(int i = 0; i < 10; i++){
    //         for(int j = 0; j < 10; j++){
    //             cin>>arr[i][j];
    //         }
    //         //cout<<endl;
    //     }
    //     ans.push_back(totalScore(arr));
    // }
    
    // for(int i : ans){
    //     cout<<i<<endl;
    // }
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<minOperations(arr, n);

    return 0;
}