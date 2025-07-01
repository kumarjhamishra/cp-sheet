#include <bits/stdc++.h>
using namespace std;

/*
Approach:
All the initial 0's means no way to make that coin -> means we don not have that coin denomination
Then when we encounter 1 -> a new coin denomination is discovered

From the coins already discovered calculate the array of number of ways to make them
*/

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> prevWays(n+1, 0), coins;
        // number of ways to make denomiation 0 is 1 by not choosing any coin
        prevWays[0] = 1;
        for(int i = 0; i < n; i++){
            // 1 based indexing
            int ways = numWays[i] - prevWays[i+1];
            // if the ways exluding those in which the denomination (i+1) can be made with previous denomination coins 
            // is negative or > 1 so, that is not possible
            if(ways < 0 || ways > 1) return {};
            // if the ways exluding the ways in which denomination (i+1) can be made with previous coins is 0 -> then do nothing
            // bcoz this coin denomination will not be included in the ans
            if(ways == 0) continue;

            // when the ways == 1 means this coin denomination will also be in the ans
            coins.push_back(i+1);
            
            // update the ways of coins from (i+1) to n with the ways of coins j - (i+1)
            for(int j = i+1; j <= n; j++) prevWays[j] += prevWays[j - (i+1)];
        }

        return coins;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> coins = {1,2,3,4,15};
    vector<int> ans = sol.findCoins(coins);
    for(int i : ans) cout << i << " ";
    return 0;
}

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