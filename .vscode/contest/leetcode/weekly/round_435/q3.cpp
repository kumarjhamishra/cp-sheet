#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// reference solution - https://leetcode.com/problems/minimum-increments-for-target-multiples-in-an-array/solutions/6360437/java-c-python-easy-and-concise-beats-100-full-explanation

class Solution {
private:
    ll gcd (ll a, ll b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    ll lcm(ll a, ll b){
        return a / gcd(a, b) * b;
    }
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        
        ll m = target.size();

        // create the mask number 
        ll fullMask = (1 << m) - 1;

        // precompute the lcm of all the possible subsets of the target 
        vector<ll> lcmSubset(fullMask + 1);

        for(ll mask = 1; mask <= fullMask; mask++){
            ll lcmOfSubset = 1;
            for(ll i = 0; i < m; i++){
                // if this bit is 1 means that target[i] is the part of the subset
                if(mask & (1 << i)) lcmOfSubset = lcm(lcmOfSubset, target[i]);
            }
            lcmSubset[mask] = lcmOfSubset;
        }

        vector<ll> dp(fullMask+ 1, LLONG_MAX/2);
        // subset is empty so operations will also be 0
        dp[0] = 0;

        for(ll i = 0; i < nums.size(); i++){
            vector<ll> newdp = dp;

            // try every new mask value
            for(ll mask = 1; mask <= fullMask; mask++){
                ll lcmOfSubset = lcmSubset[mask];

                // compute the operations needed to change this nums[i] to be a multiple of lcm of curr target subset
                //ll cost = (lcmOfSubset - (nums[i] % lcmOfSubset)) % lcmOfSubset;
                ll cost = (nums[i] % lcmOfSubset == 0 ? 0 : lcmOfSubset - (nums[i] % lcmOfSubset));

                // update dp array from each of the every possible previos mask state
                for(ll old = 0; old <= fullMask; old++){
                    ll newmask = (old | mask);
                    newdp[newmask] = min(newdp[newmask], dp[old] + cost);
                }
            }

            // for next iteration
            dp = newdp;
        }

        return (int)dp[fullMask];
    }
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {7,9,10}, target = {7};
    cout << sol.minimumIncrements(nums, target);

    return 0;
}