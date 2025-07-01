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
    vvi dp;
    int f(int l, int r, vi& cuts){
        // base cases
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int cost = 1e9;
        for(int i = l; i <= r; i++){
            // if made a cut at cuts[i] then
            int currCost = (cuts[r+1] - cuts[l-1]) + f(l, i-1, cuts) + f(i+1, r, cuts);
            cost = min(cost, currCost);
        }
        return dp[l][r] = cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        dp.resize(101, vi(101, -1));
        return f(1, cuts.size() - 2, cuts);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}

