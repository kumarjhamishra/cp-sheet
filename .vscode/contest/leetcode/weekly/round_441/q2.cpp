#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
unordered_map<int, vector<int>> indices;

int find_pos(int num, int idx){
    int n = indices[num].size(), l = 0, r = n-1;
    while(l <= r){
        int mid = l + ((r - l) >> 1);
        if(indices[num][mid] == idx){
            return mid;
        }
        else if(indices[num][mid] > idx) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

int find_min_dist(int num, int idx, int n){
    int m = indices[num].size();

    // find this index idx in the list of indices[num]
    int pos = find_pos(num, idx);

    // we need to find for the left and right indices near to idx in order to find the min distance
    int min_dist = 1e9;
    // distance from left side
    int dist = abs(indices[num][pos] - indices[num][(pos - 1 + m) % m]);
    min_dist = min(min_dist, dist);
    dist = n - dist;
    min_dist = min(min_dist, dist);

    // distance from right side
    dist = abs(indices[num][(pos + 1) % m] - indices[num][pos]);
    min_dist = min(min_dist, dist);
    dist = n - dist;
    min_dist = min(min_dist, dist);

    return min_dist;
}
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {   
        // stores all the indices for each unique element
        
        int n = nums.size(), q = queries.size();

        for(int i = 0; i < n; i++) indices[nums[i]].push_back(i);
        
        vector<int> ans(q, -1);
        for(int i = 0; i < q; i++){
            int idx = queries[i];
            if(indices[nums[idx]].size() == 1) continue;
            
            ans[i] = find_min_dist(nums[idx], idx, n);
        }

        // for(int i : ans){
        //     cout << i << " ";
        // }
        // cout << endl;
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1,2,3,4};
    vector<int> queries = {0,1,2,3};
    Solution s;
    s.solveQueries(nums, queries);

    return 0;
}