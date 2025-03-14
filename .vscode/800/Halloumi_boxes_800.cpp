
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    //cout<<"enter t: ";
    int t;
    cin>>t;
    
    vector<string> ans;
    while(t--){
        int n, k;
        //cout<<"enter n and k: ";
        cin >> n >> k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        if(k >= 2) ans.push_back("YES");
        else{
            if(is_sorted(arr.begin(), arr.end())) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }
    
    for(string s : ans){
        cout<<s<<endl;
    }
    return 0;
}