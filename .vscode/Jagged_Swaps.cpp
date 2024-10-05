// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSortingPossible(int &n, vector<int> &arr){
    //if(is_sorted(arr.begin(), arr.end())) return true;
    
    return arr[0] == 1;
}

int main() {
    int t;
    cin>>t;
    vector<string> ans;
    while(t--){
        int n; 
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        if(isSortingPossible(n, arr)) ans.push_back("YES");
        else ans.push_back("NO");
        
    }
    
    for(string i : ans){
        cout<<i<<endl;
    }

    return 0;
}