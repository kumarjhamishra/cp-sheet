// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string whoWins(int &n){
    if((n-1) % 3 == 0 || (n+1) % 3 == 0) return "First";
    return "Second";
}

int main() {
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n; 
        cin>>n;
        ans.push_back(whoWins(n));
    }
    
    for(string i : ans){
        cout<<i<<endl;
    }

    return 0;
}