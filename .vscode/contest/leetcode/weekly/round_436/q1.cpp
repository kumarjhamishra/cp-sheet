#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // first for all the columns from 1 to n-1
        for(int col = 1; col < n; col++){
            int r = 0, c = col;
            vector<int> diagonal;
            while(r < n && c < n){
                diagonal.push_back(grid[r][c]);
                r = r+1, c = c+1;
            }

            sort(diagonal.begin(), diagonal.end());
            r = 0, c = col;
            int idx = 0;
            while(r < n && c < n && idx < diagonal.size()){
                grid[r][c] = diagonal[idx++];
                r = r+1, c = c+1;
            }
        }

        // now for all the rows from 0 to n-1
        for(int row = 0; row < n; row++){
            int r = row, c = 0;

            vector<int> diagonal;
            while(r < n && c < n){
                diagonal.push_back(grid[r][c]);
                r = r+1, c = c+1;
            }

            sort(diagonal.begin(), diagonal.end(), greater<int>());
            r = row, c = 0;
            int idx = 0;
            while(r < n && c < n && idx < diagonal.size()){
                grid[r][c] = diagonal[idx++];
                r = r+1, c = c+1;
            }
        }

        return grid;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {{1}};
    Solution sol;
    sol.sortMatrix(grid);
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}