// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
// #include <algorithm>
// #include <vector>

using namespace std;

void solve(int &n, vector<int> &arr){
    sort(arr.begin(), arr.end());
    
    if(arr[0] == arr.back()){
        cout<<-1<<endl;
        return ;
    }
    
    int it = 0;
    while(arr[it] == arr[0]) it++;
    
    cout<<it <<" "<< n-it<<endl;
    for(int i = 0; i < it; i++) cout<<arr[i]<<" ";
    cout<<endl;
    for(int i = it; i < n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return ;
}

int main() {
    int t;
    cin>>t;
    //vector<pair<>>
    while(t--){
        int n; 
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        solve(n, arr);
    }

    return 0;
}