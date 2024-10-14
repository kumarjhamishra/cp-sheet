// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int remainingEfficiency(vector<int> &efficiency){
    int pos = 0, neg = 0;
    
    for(int i : efficiency){
        if(i >= 0) pos += i;
        else neg += abs(i);
    }
    //cout<<"pos: "<<pos<<" neg: "<<neg<<endl;
    return neg - pos;
}

int main() {
    int t;
    cin>>t;
    vector<int> ans;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n-1);
        for(int i = 0; i < n-1; i++){
            cin>>arr[i];
        }
        ans.push_back(remainingEfficiency(arr));
    }
    
    for(int i : ans){
        cout<<i<<endl;
    }

    return 0;
}