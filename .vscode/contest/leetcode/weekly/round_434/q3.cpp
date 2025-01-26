#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int final_max_freq = INT_MIN, freq_of_k = 0;

        // count the total frequecy of k in nums
        int n = nums.size();

        // mark start and end index of each unique element and also their total frequency and 
        // also the frequency of k till each index
        vector<int> start(51, -1), freqK(n, 0), end(51, -1), freq(51, 0);
        for(int i = 0; i < n; i++){
            if(start[nums[i]] == -1) start[nums[i]] = i;
            end[nums[i]] = i;
            freq[nums[i]]++;
            if(nums[i] == k){
                if(i == 0) freqK[i] = 1;
                else freqK[i] = freqK[i-1] + 1;
            }
        }

        freq_of_k = freqK[n-1];
        for(int i = 1; i <= 50; i++){
            int start_i = start[i];

            // means this element is not present
            if(start_i == -1) continue;

            int end_i = end[i];

            // total k which comes in the inside the subarray of number i
            int curr_freq_k = freqK[end_i] - (start_i != 0 ? freqK[start_i-1] : 0);

            final_max_freq = max(final_max_freq, freq_of_k - curr_freq_k + freq[i]);
        }

        return final_max_freq;
        
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