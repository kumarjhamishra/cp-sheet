// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int &n, int &k, vector<int> &arr){
    vector<int> count(100, 0);
    
    for(int i : arr) count[i-1]++;
    
    return count[k-1] > 0;
}

int main() {
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        
        ans.push_back(isPossible(n, k, arr) ? "YES" : "NO");
    }
    
    for(string i : ans){
        cout<<i<<endl;
    }

    return 0;
}