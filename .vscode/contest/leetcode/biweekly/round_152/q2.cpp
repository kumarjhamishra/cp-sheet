#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
private:
    vector<vector<int>> grid;
public:
    Spreadsheet(int rows)
    {
        grid.resize(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(string formula)
    {
        size_t idx = formula.find('+');
        int val1 = 0, val2 = 0;
        if(formula[1] >= 'A' && formula[1] <= 'Z'){
            int col = formula[1] - 'A';
            int row = stoi(formula.substr(2, idx)) - 1;
            val1 = grid[row][col];
        }
        else val1 = stoi(formula.substr(1, idx));

        if(formula[idx + 1] >= 'A' && formula[idx + 1] <= 'Z'){
            int col = formula[idx + 1] - 'A';
            int row = stoi(formula.substr(idx + 2)) - 1;
            val2 = grid[row][col];
        }
        else val2 = stoi(formula.substr(idx + 1));
        
        return val1 + val2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }

    return 0;
}