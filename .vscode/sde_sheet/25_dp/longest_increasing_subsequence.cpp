/*
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
class Solution {
private:
    /*
    int n;
    vi nums;
    vvi dp;
    int f(int i, int pre){
        // base case
        if(i == n){
            return 0;
        }
        if(dp[i][pre+1] != -1) return dp[i][pre+1];

        int take = 0, not_take = 0;
        if(pre == -1 || nums[i] > nums[pre]) take = 1 + f(i+1, i);
        not_take = f(i+1, pre);

        return dp[i][pre+1] = max(take, not_take);
    }
    */

    int binarySearch(vi& lis, int target){
        int l = 0, r = lis.size()-1, ans;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(lis[mid] >= target){
                ans = mid;
                r = mid-1;
                if(lis[mid] == target) return ans;
            }
            else l = mid+1;
        }
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        //cout << "hello" << endl; 
        n = nums.size();
        this->nums = nums;
        dp.resize(n, vi(n, -1));
        return f(0, -1);
        */


        // optimised approach

        // maintain a list of longest increasing subsequence
        int n = nums.size();
        vi lis;
        for(int i = 0; i < n; i++){
            if(lis.empty() || lis.back() < nums[i]) lis.push_back(nums[i]);
            else{
                // in the current LIS replace one of the element with curr ele so to maintain the LIS
                int idx = binarySearch(lis, nums[i]);
                lis[idx] = nums[i];
            }
        }

        return lis.size();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vi nums = {7,7,7,7,7,7,7};
    cout << sol.lengthOfLIS(nums);
    return 0;
}