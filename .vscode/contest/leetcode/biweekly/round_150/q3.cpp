#include <bits/stdc++.h>
using namespace std;
using d = double;

class Solution
{
private:
    bool isValid(vector<vector<d>> &squares, int &n, d y_line, d target)
    {
        d area = 0;
        for (int i = 0; i < n; i++)
        {
            d y = (d)squares[i][1], l = (d)squares[i][2], x = (d)squares[i][0];
            if (y >= y_line)
                continue;

            else if (y_line >= y + l)
                area += (d)l * l;
            else
                area += (d)l * (y_line - y);
        }

        return area >= target;
    }

public:
    double separateSquares(vector<vector<int>> &squares)
    {
        int n = squares.size();
        vector<vector<d>> d_squares;

        for (int i = 0; i < n; i++)
        {
            d x = (d)squares[i][0], y = (d)squares[i][1], l = (d)squares[i][2];
            d_squares.push_back({x, y, l});
        }

        // while counting the total area this time we don't want to add the overlapping area twice
        sort(d_squares.begin(), d_squares.end());

        d low = 2e9, high = 0, totalArea = 0;
        d prev_x_end = -1, prev_y_top = -1, prev_y_bottom = -1;
        for (int i = 0; i < n; i++)
        {
            d x = (d)d_squares[i][0], y = (d)d_squares[i][1], l = (d)d_squares[i][2];
            totalArea += (d)l * l;
            if (y < low)
                low = y;
            if (y + l > high)
                high = y + l;

            // check for overlapping
            if (x < prev_x_end)
            {
                // subtract the double counting of overlapped area
                d b = (d)prev_x_end - x;
                d y_top = min(prev_y_top, y + l), y_bottom = max(prev_y_bottom, y);
                d l = y_top - y_bottom;
                if (l > 0)
                {
                    totalArea -= (d)l * b;
                }
            }
            prev_x_end = x+l;
            prev_y_top = y + l;
            prev_y_bottom = y;
            // cout << "total: " << totalArea << endl;
            // cout << "prev_x_end: " << prev_x_end << "prev_y_top: " << prev_y_top << "prev_y_bottom: " << prev_y_bottom << endl;
        }


        // below the y line the area should be totalArea/2
        d firstHalfArea = totalArea / 2.0;
        while (high - low >= 1e-5)
        {
            d mid = low + (high - low) / 2.0;
            if (isValid(d_squares, n, mid, firstHalfArea))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }

        return (d)high;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<vector<int>> sqaures = {{0,0,2},{1,1,1}};
    cout << sol.separateSquares(sqaures);

    return 0;
}