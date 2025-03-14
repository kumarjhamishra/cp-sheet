// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> &arr, int &n){
    vector<int> ans;
    ans.push_back(arr[0]);
    
    for(int i = 1; i < n; i++){
        if(arr[i] < ans.back()) ans.push_back(arr[i]);
        ans.push_back(arr[i]);
    }
    
    return ans;
}

int main() {
    int t;
    cin>>t;
    vector<vector<int>> ans;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        ans.push_back(f(arr, n));
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i].size()<<endl;
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}