// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int countOperations(int &n, string &x, int &m, string &s){
    int operations = 0;
    if(n >= m){
        if(x.find(s) != string::npos) return 0;
        x += x;
        if(x.find(s) != string::npos) return 1;
        return -1;
    }
    
    // x chota hai
    
    while(x.size() <= 2*m){
        x += x;
        operations++;
        if(x.find(s) != string::npos) return operations;
            
    }
    
    
    return -1;
}

int main() {
    int t;
    cin>>t;
    vector<int> ans;
    while(t--){
        int n, m;
        cin>>n>>m;
        string x, s;
        cin>>x;
        cin>>s;
        
        ans.push_back(countOperations(n, x, m, s));
    }
    
    for(int i : ans){
        cout<<i<<endl;
    }

    return 0;
}