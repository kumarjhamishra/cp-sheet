#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minCosts(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> ans(n, -1);

        // store the minimum element till index i that will be the minimum cost for index i
        int miniCost = INT_MAX;
        for(int i = 0; i < n; i++){
            miniCost = min(miniCost, cost[i]);
            ans[i] = miniCost;
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cost = {};
    Solution sol;
    //for(int )

    return 0;
}