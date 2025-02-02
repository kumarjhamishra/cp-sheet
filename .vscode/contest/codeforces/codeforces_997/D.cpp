#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }   

    int countGood = 0;
    // we need to count the subarrays till the window size <= n
    for(int windowSize = 1; windowSize <= n; windowSize++){
        // if the windowSize is odd it will definitely be a good subarray
        if(windowSize % 2 == 1){
            countGood += n - (windowSize - 1);
        }
        else{
            for(int i = 0; i <= n - windowSize; i++){
                vector<int> subA(a.begin()+i, a.begin()+i+windowSize);
                sort(subA.begin(), subA.end());

                // it's a 0-based indexing
                int floor_idx = floor((double)(windowSize + 1)/2) - 1;
                int ceil_idx = ceil((double)(windowSize + 1)/2) - 1;
                if(subA[floor_idx] == subA[ceil_idx]) countGood++;
            }
        }
    }

    cout << countGood << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}