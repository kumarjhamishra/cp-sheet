#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0), count = 0;
        for(int i = 0; i < n-1; i++){
            leftSum += nums[i];
            rightSum -= nums[i];

            if(abs(leftSum - rightSum) % 2 == 0) count++;
        }

        return count;
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