// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minMoves(int &n, string &s){
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            int cnt = 0;
            while(i < n && s[i] == '.'){
                i++;
                cnt++;
                if(cnt > 2) return 2;
            }
            
            ans += cnt;
            
        }
    }
    
    return ans;
}

int main() {
    int t;
    cin>>t;
    vector<int> ans;
    while(t--){
        int n; 
        cin>>n;
        string s;
        cin>>s;
        ans.push_back(minMoves(n, s));
    }
    
    for(int i : ans){
        cout<<i<<endl;
    }

    return 0;
}