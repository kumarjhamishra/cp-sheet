#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int f(vector<int> &nums){
        int minSum = INT_MAX;
        int idx_with_smallest_pair_sum = -1;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] + nums[i+1] < minSum){
                minSum = nums[i] + nums[i+1];
                idx_with_smallest_pair_sum = i;
            }   
        }

        return idx_with_smallest_pair_sum;
    }
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        
        int totalSteps = 0;
        while(true){
            if(is_sorted(nums.begin(), nums.end()) || nums.size() == 1){
                return totalSteps;
            }

            // get the index which formst the smallest pair sum
            int idx = f(nums);
            vector<int> temp;
            int i = 0; 
            while(i < nums.size()){
                if(i == idx){
                    temp.push_back(nums[i] + nums[i+1]);
                    i++;
                }
                else{
                    temp.push_back(nums[i]);
                }
                i++;
            }

            nums = temp;
            totalSteps++;

        }

        return totalSteps;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    cout << sol.minimumPairRemoval(nums) << endl; // Output: 1

    return 0;
}