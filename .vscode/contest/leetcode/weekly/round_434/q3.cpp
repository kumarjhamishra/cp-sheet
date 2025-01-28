#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> freq(51, 0);
        for(int i : nums) freq[i]++;

        int maxFreq = INT_MIN;
        for(int num = 1; num <= 50; num++){
            if(freq[num] == 0) continue;

            // modified kadane's also
            int maxSubarrySum = 0, currSum = 0;
            for(int i = 0; i < n; i++){
                // if it's k treat it a element whose value is -1
                if(nums[i] == k) currSum--;
                // if this nums[i] is that number num for which we are checking then treat it as a element of value 1
                if(nums[i] == num) currSum++;

                currSum = max(0, currSum);
                maxSubarrySum = max(maxSubarrySum, currSum);
            }
            maxFreq = max(maxFreq, maxSubarrySum);
        }

        return freq[k] + maxFreq;
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