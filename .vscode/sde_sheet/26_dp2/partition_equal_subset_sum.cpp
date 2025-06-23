// const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
// const auto __ = []() {
//     struct ___ {
//         static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//     };
//     std::atexit(&___::_);
//     return 0;
// }();

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
private:
    int n;
    vvi dp;

    bool f(int i, int target, vi& nums){
        // base case
        if(target == 0) return true;
        if(i == n || target < 0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = (f(i+1, target - nums[i], nums) || f(i+1, target, nums));
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2) return false;

        this->n = nums.size();
        dp.resize(n, vi(sum/2 + 1, -1));
        return f(0, sum/2, nums);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

