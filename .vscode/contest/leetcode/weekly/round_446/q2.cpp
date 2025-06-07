#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /*
    int f(int i, int prev_i, int &n, vector<int> &nums, vector<vector<int>> &dp){
        // base case
        if(i == n){
            return 0;
        }

        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];

        int maxLength = 0;
        // making this element the part of previos subsequence
        if(prev_i == -1 || nums[i] >= nums[prev_i]){
            maxLength = max(maxLength, 1 + f(i+1, i, n, nums, dp));
        }
        // starting a new subsequence from here
        maxLength = max(maxLength, f(i+1, prev_i, n, nums, dp));
        return dp[i][prev_i+1] = maxLength;
        
    }
        */
public:
    int maximumPossibleSize(vector<int> &nums)
    {
        int n = nums.size();
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // i and prev_i
        //return f(0, -1, n, nums, dp);

        // vector<int> ans;

        // for(int i : nums) {
        //     auto it = upper_bound(ans.begin(), ans.end(), i);  // non-decreasing
        //     if(it == ans.end()) {
        //         ans.push_back(i);
        //     } else {
        //         *it = i;
        //     }
        // }
        // return ans.size();


        int count = 0, i = 0;
        while(i < n){
            count++;
            int j = i+1;
            while(j < n && nums[j] < nums[i]) j++;
            i = j;
        }

        return count;

    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {19,80,63,74};
    Solution sol;
    cout << sol.maximumPossibleSize(nums);

    return 0;
}