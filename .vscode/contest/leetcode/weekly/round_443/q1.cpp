#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j >= max(0, i-nums[i]); j--){
                sum += nums[j];
            }
        }

        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        //solve();
    }

    return 0;
}