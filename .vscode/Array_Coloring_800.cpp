// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

bool sameParity(vector<int> &arr, int &n){
    int oddCnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0) oddCnt++;
    }
    
    return oddCnt % 2 == 0;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        if(sameParity(arr, n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}