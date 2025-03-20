#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        unordered_map<int, bool> visited;
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(!visited[nums[i]] && nums[i] > 0){
                visited[nums[i]] = true;
                sum += nums[i];
            }
        }

        if(sum == 0){
            sum = *max_element(nums.begin(), nums.end());
        }

        cout << sum << endl;
        return sum;
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