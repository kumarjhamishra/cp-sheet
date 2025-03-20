#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void decrement(vector<int> &nums, int l, int r, int val){
        for(int i = l; i <= r; i++) nums[i] -= val;
    }

    bool allZero(vector<int> &nums, int &n){
        for(int i = 0; i < n; i++){
            if(nums[i] != 0) return false;
        }

        return true;
    }

    void printNums(vector<int> &nums, int &n){
        cout << "printing nums" << endl;
        for(int i = 0; i < n; i++) cout << nums[i] << " ";
        cout << endl;
    }
    
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), q = queries.size();

        for(int i = 0; i < q; i++){
            decrement(nums, queries[i][0], queries[i][1], queries[i][2]);
            printNums(nums, n);
            if(allZero(nums, n)) return i + 1;
        }

        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {{0,2,1},{0,2,1},{1,1,3}};
    cout << sol.minZeroArray(nums, queries) << endl;

    return 0;
}