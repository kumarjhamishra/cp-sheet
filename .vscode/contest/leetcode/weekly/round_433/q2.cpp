#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
private:
    const int mod = 1e9+7;
public:
    int minMaxSums(vector<int>& nums, int k) {
        ll n = nums.size();


        // calculating ncr using pascal traingle formula
        vector<vector<ll>> nCr(n+1, vector<ll> (k+1, 0));

        nCr[0][0] = 1;
        for(ll i = 1; i <= n; i++){
            nCr[i][0]= 1;

            for(ll l = 1; l <= k; l++){
                nCr[i][l] = (nCr[i-1][l-1] + nCr[i-1][l]) % mod;
            }
        }

        sort(nums.begin(), nums.end());

        ll ans = 0;
        // for the minimum element of the subsequences
        for(ll i = 0; i < n; i++){
            ll noOfSubsequences = 0; // counts the no of subsequences for which this element will be minimum   
            // and that will be n-i-1 C l-1
            // length of the subsequence will be from 1 to k
            for(ll l = 1; l <= k; l++){
                noOfSubsequences = (noOfSubsequences + nCr[n-i-1][l-1]) % mod;
            }

            ans = (ans + (1ll * nums[i] * noOfSubsequences) % mod) % mod;

        }

        // for the maximum element of subsequences
        // instead of changing the formula of no of subsequences reverse the nums

        reverse(nums.begin(), nums.end());
        for(ll i = 0; i < n; i++){
            ll noOfSubsequences = 0; // counts the no of subsequences for which this element will be minimum   
            // and that will be n-i-1 C l-1
            // length of the subsequence will be from 1 to k
            for(ll l = 1; l <= k; l++){
                noOfSubsequences = (noOfSubsequences + nCr[n-i-1][l-1]) % mod;
            }

            ans = (ans + (1ll * nums[i] * noOfSubsequences) % mod) % mod;

        }

        return ans;

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