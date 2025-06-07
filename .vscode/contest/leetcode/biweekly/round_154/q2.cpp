#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        // base case
        if(nums.size() <= 2) return nums.size();

        int maxi = *max_element(nums.begin(), nums.end());

        int totalBits = 0;
        while((1 << totalBits) <= maxi) totalBits++;

        int maxNumber = (1 << totalBits) - 1;

        return maxNumber + 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {1,2, 3};
    cout << sol.uniqueXorTriplets(nums) << endl;

    return 0;
}