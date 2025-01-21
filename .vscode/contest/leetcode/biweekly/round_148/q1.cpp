#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = abs(nums[0] - nums[n-1]);

        for(int i = 1; i < n; i++){
            maxDiff = max(maxDiff, abs(nums[i] - nums[i-1]));
        }

        return maxDiff;
        
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        //solve();
    }

    return 0;
}