#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvll = vector<vector<ll>>;
using pii = pair<int, int>;

// class Solution {
// private:
//     long long f(ll i, int k, vector<int>& limits, vvll& rowSum, ll& n, ll& m, vvll& dp){
//         if(i == n) return 0;
//         if(k == 0) return 0;
//         if(dp[i][k] != -1) return dp[i][k];

//         ll ans = 0;
//         for(int _k = 0; _k <= k && _k <= limits[i]; _k++){
//             if(_k > m) break;
//             if(_k == 0) ans = max(ans, f(i+1, k, limits, rowSum, n, m, dp));
//             else ans = max(ans, rowSum[i][_k-1] + f(i+1, k-_k, limits, rowSum, n, m, dp));
//         }

//         return dp[i][k] = ans;
//     }
// public:
//     long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
//         ll n = grid.size(), m = grid[0].size();
//         vvll rowSum(n, vector<ll>(grid[0].size(), 0));

//         vvll dp(n, vector<ll>(k+1, -1));
//         for(ll i = 0; i < n; i++){
//             // sort in decreasing
//             sort(grid[i].begin(), grid[i].end(), greater<int>());
//             for(ll j = 0; j < m; j++){
//                 rowSum[i][j] = 1ll * grid[i][j] + (j > 0 ? rowSum[i][j-1] : 0);
//             }
//         }

//         return f(0, k, limits, rowSum, n, m, dp);
//     }
// };


class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        // make a max heap
        priority_queue<pii> maxHeap;

        ll n = grid.size(), m = grid[0].size();

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                maxHeap.push({grid[i][j], i});
            }
        }

        ll sum = 0;
        while(k > 0 && !maxHeap.empty()){
            pii top = maxHeap.top();
            maxHeap.pop();
            int val = top.first;
            int row = top.second;

            if(limits[row] > 0){
                limits[row]--;
                k--;
                sum += 1ll * val;
            }
        }

        return sum;

    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<vector<int>> grid = {{1,2},{3,4}};
    vector<int> limits = {1,2};
    int k = 2;
    cout << s.maxSum(grid, limits, k) << endl;

    return 0;
}