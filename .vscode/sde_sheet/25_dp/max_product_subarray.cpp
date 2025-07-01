/*
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        int ans = INT_MIN, n = nums.size(), product;
        for(int i = 0; i < n; i++){
            product = 1;
            for(int j = i; j < n; j++){
                product *= nums[j];
                ans = max(ans, product);
            }
        }

        return ans;
        */

        // optimised approach
        int maxProductEndingHere = 1, minProductEndingHere = 1, ans = INT_MIN;
        for(int num : nums){
            int temp1 = maxProductEndingHere*num, temp2 = minProductEndingHere*num;
            maxProductEndingHere = max({num, temp1, temp2});
            minProductEndingHere = min({num, temp1, temp2});
            //cout << "maxProductEndingHere: " << maxProductEndingHere << " minProductEndingHere: " << minProductEndingHere << endl;
            ans = max(ans, maxProductEndingHere);
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vi nums = {-4,-3,-2};
    cout << sol.maxProduct(nums);
    return 0;
}