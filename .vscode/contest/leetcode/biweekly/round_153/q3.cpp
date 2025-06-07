#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
#define pb push_back

// below approach gave MLE -> memory limit exceeded
// class Solution
// {

// private:
//     ll f(int i, int totalPartitions, int prev_i, int &n, int &k, vll &preNums, vll &preCost, vvvll &dp){

//         // base case
//         if(i == n){
//             if(prev_i == n-1) return 0;

//             // estimate the cost of last partition if the final partition is not at n-1
//             ll finalCost = preCost[i-1] - (prev_i != -1 ? preCost[prev_i] : 0);
//             ll finalPartition = (preNums[i-1] + 1ll * (totalPartitions + 1) * k) * (finalCost);

//             return finalPartition;
//         }

//         if(dp[i][totalPartitions+1][prev_i+1] != -1) return dp[i][totalPartitions+1][prev_i+1];

//         // decide whether at index i we want to make a new partition or not

//         ll notPartition = 0, partition = 0;
//         // case of not doing the partition
//         notPartition = 0 + f(i+1, totalPartitions, prev_i, n, k, preNums, preCost, dp);
//         // case of partition
//         ll totalCost = preCost[i] - (prev_i != -1 ? preCost[prev_i] : 0);
//         partition = (preNums[i] + 1ll * (totalPartitions+1) * k) * (totalCost) + f(i+1, totalPartitions+1, i, n, k, preNums, preCost, dp);

//         return dp[i][totalPartitions+1][prev_i+1] = min(notPartition, partition);
//     }
// public:
//     long long minimumCost(vector<int> &nums, vector<int> &cost, int k)
//     {
//         int n = nums.size();
//         // maintain the prefix sum of nums and cost for effetive calculation
//         vll preNums(n, 0), preCost(n, 0);
//         preNums[0] = 1ll * nums[0], preCost[0] = 1ll * cost[0];
//         for(int i = 1; i < n; i++){
//             preNums[i] = (nums[i] + preNums[i-1]);
//             preCost[i] = (cost[i] + preCost[i-1]);
//         }

//         // for(int i = 0; i < n; i++){
//         //     cout << preNums[i] << " ";
//         // }
//         // cout << endl;
//         // for(int i = 0; i < n; i++){
//         //     cout << preCost[i] << " ";
//         // }

//         /*
//         in the recursion 3 states will be changes, {i, total partitions till now, prev index of partition}

//         i ranges from 0 to n-1
//         total partitions ranges from 1 to n
//         prev_i ranges from -1 to n-1
//         */
//         int i = 0, totalPartitions = 0, prev_i = -1;

//         vvvll dp(n+2, vvll(n+2, vll(n+2, -1)));
//         return f(i, totalPartitions, prev_i, n, k, preNums, preCost, dp);
//     }
// };

class Solution
{
private:
    ll f(int start, int totalPartitions, int &k, int &n, vector<ll> &preNum, vector<ll> &suffCost, vvll &dp){
        // base case
        if(start == n){
            // coz no more partitions are possible
            return 0;
        }

        if(dp[start][totalPartitions] != -1) return dp[start][totalPartitions];

        ll totalCost = LLONG_MAX;
        // we can end the current subarray from start till n-1
        for(int end = start; end < n; end++){
            ll currentCost = (preNum[end] + 1ll * (totalPartitions) * k) + (suffCost[start] - (end + 1 < n ? suffCost[end+1] : 0)) + f(end+1, totalPartitions+1, k, n, preNum, suffCost, dp);
            totalCost = min(totalCost, currentCost);
        }

        return dp[start][totalPartitions] = totalCost;
    }
public:
    long long minimumCost(vector<int> &nums, vector<int> &cost, int k)
    {
        int n = nums.size();
        vector<ll> preNum(n, 0), suffCost(n, 0);
        preNum[0] = 1ll * nums[0], suffCost[n-1] = 1ll * nums[n-1];
        
        for(int i = 1; i < n; i++){
            preNum[i] = (nums[i] + preNum[i-1]);
            suffCost[n-i-1] = (nums[i] + suffCost[n-i]);
        }

        vvll dp(n, vll(n+1, -1));
        return f(0, 1, k, n, preNum, suffCost, dp);

    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vi nums = {4,8,5,1,14,2,2,12,1};
    vi cost = {7,2,8,4,2,2,1,1,2};
    int k = 7;
    cout << sol.minimumCost(nums, cost, k);

    return 0;
}