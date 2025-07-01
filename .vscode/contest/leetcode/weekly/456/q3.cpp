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

class Solution
{
private:
    int n, ans = INT_MAX;
    vi nums, prefix_xor;
    vvi dp;

    int f(int i, int partition){
        // base cases
        if(partition == 0){
            return prefix_xor.back() ^ prefix_xor[i-1];
        }

        if(dp[i][partition] != -1) return dp[i][partition];

        // at all the valid j's we can make the make the partion(end) this current subarray started at index i
        int _xor = 0, currMaxXor = INT_MAX;
        for(int j = i; j <= n-partition-1; j++){
            _xor = prefix_xor[j];
            if(i > 0) _xor ^= prefix_xor[i-1];
            currMaxXor = min(currMaxXor, max(_xor, f(j+1, partition-1)));
            
        }
        
        return dp[i][partition] = currMaxXor;
    }
public:
    int minXor(vector<int> &nums, int k)
    {
        this->nums = nums;
        this->n = nums.size();
        prefix_xor.resize(n);
        prefix_xor[0] = nums[0];
        for(int i = 1; i < n; i++) prefix_xor[i] = prefix_xor[i-1] ^ nums[i];
        
        // base cases
        if(n == 1) return prefix_xor[0];
        if(k == 1) return prefix_xor.back();
        
        dp.resize(n, vi(k+1, -1));

        return f(0, k-1);;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vi nums = {1,1,2,3,1};
    int k = 2;
    cout << sol.minXor(nums, k);

    return 0;
}