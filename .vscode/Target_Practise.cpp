// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int totalScore(vector<vector<char>> &arr){
    int ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(arr[i][j] == 'X'){
                if(i == 0 || i == 9 || j == 0 || j == 9) ans += 1;
                else if(i == 1 || i == 8 || j == 1 || j == 8) ans += 2;
                else if(i == 2 || i == 7 || j == 2 || j == 7) ans += 3;
                else if(i == 3 || i == 6 || j == 3 || j == 6) ans += 4;
                else ans += 5;
            }
        }
    }
    
    return ans;
}

int main() {
    int t;
    cin>>t;
    vector<int> ans;
    while(t--){
        vector<vector<char>> arr(10, vector<char>(10));
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cin>>arr[i][j];
            }
            //cout<<endl;
        }
        ans.push_back(totalScore(arr));
    }
    
    for(int i : ans){
        cout<<i<<endl;
    }

    return 0;
}