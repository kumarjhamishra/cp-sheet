#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
private:
    int m,n;
    vvi dp;

    int f(int i, int j, vvi &grid){
        // base case
        // destination
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(i >= m || j >= n) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int pathSum = grid[i][j];
        pathSum += min(f(i+1, j, grid), f(i, j+1, grid));
        return dp[i][j] = pathSum;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        this->m = grid.size(), this->n = grid[0].size();

        dp.resize(m, vi(n, -1));
        return f(0, 0, grid);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}