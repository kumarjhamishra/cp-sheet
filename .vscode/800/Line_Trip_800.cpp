
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    //cout<<"enter t: ";
    int t;
    cin>>t;
    
    vector<int> ans;
    while(t--){
        int n, x;
        //cout<<"enter n and x: ";
        cin >> n >> x;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int maxi = max(arr[0]-0, 2*(x-arr[n-1]));
        for(int i = 1; i < n; i++){
            maxi = max(maxi, arr[i]-arr[i-1]);
        }
        
        ans.push_back(maxi);
    }
    
    for(int i : ans){
        cout<<i<<endl;
    }
    return 0;
}