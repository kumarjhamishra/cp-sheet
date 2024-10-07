// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
//#include <bits/stdc++.h>

using namespace std;

bool canBeGood(vector<int> &arr, int &n){
    if(n == 2) return true;
    
    unordered_map<int, int> mp;
    for(int i : arr) mp[i]++;
    
    if(mp.size() > 2) return false;
    if(mp.size() == 1) return true;
    
    int freq = (n+1)/2;
    for(auto i : mp){
        if(i.second != freq && i.second != freq-1) return false;
    }
    // auto first = mp.begin();
    // auto last = mp.end();
    // last--; // pointer to the last key value pair
    return true;
}

int main() {
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];
        
        if(canBeGood(arr, n)) ans.push_back("Yes");
        else ans.push_back("No");
    }
    
    for(string s : ans) cout<<s<<endl;

    return 0;
}