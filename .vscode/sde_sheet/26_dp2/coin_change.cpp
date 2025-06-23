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

    int f(int i, int amount, vi& coins){
        // base case
        if(amount == 0) return 0;
        if(i == n) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 1e9, notTake = 1e9;
        if(amount >= coins[i]) take = 1 + f(i, amount - coins[i], coins);
        notTake = f(i+1, amount, coins);
        return dp[i][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        this->n = coins.size();

        dp.resize(n, vi(amount+1, -1));
        int ans = f(0, amount, coins);
        return ans < 1e9 ?  ans : -1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

