#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfGoodNumbers(vector<int> &nums, int k)
    {   
        int countGood = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            bool check = true;
            if(i-k >= 0 && nums[i-k] >= nums[i]) check = false;
            if(i+k < n && nums[i+k] >= nums[i]) check = false;

            countGood += check ? nums[i] : 0;
        }

        return countGood;
    }
};


    int
    main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Solution sol;
    // vector<int> nums = {};
    // int k = ;
    // sol.sumOfGoodNumbers(nums, k);

    return 0;
}