
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        if(k >= 2) cout<<"YES";
        else{
            if(is_sorted(arr.begin(), arr.end())) cout<<"YES";
            else cout<<"NO";
        }
    }
    return 0;
}