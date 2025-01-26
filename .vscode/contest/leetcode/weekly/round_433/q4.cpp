#include <bits/stdc++.h>
using namespace std;

/*
    saar of the solution:
    Agr koi element kisi subarray ka max banna chaahta hai to find ki use left me pehla bada element kaha mil raha and in right also.
    Ab ye jo range me jo khel hoa ab isi me hoga
*/



typedef long long ll;
class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int K) {
        ll k = K;
        ll n = nums.size(), ans = 0;

        {
            // stack
            vector<ll> s;
            // to store the indices of the elements greater than your element in the nearest left and in the nearest right
            vector<ll> left(n, -1), right(n, n);
            
            for(ll i = 0; i < n; i++){
                // for the previous elements of stack is curr element is >= than it then it will be the greater element in right for them
                while(!s.empty() && nums[s.back()] <= nums[i]){
                    right[s.back()] = i;
                    s.pop_back();
                }
                
                // now if the stack is not empty then it contains the element > curr element and for the left[i] for curr element
                if(!s.empty()) left[i] = s.back();

                s.push_back(i);
            }


            for(ll i = 0; i < n; i++){
                // standing at nums[i] subarray of size at most k and where the nums[i] will be maximum
                // to maintain the window of at most k elements from both left and right
                left[i] = max(left[i], i-k);
                right[i] = min(right[i], i+k);

                // in this range the nums[i] is the maximum 

                ll left_diff = i - left[i];
                ll right_diff = right[i] - i;
                ll min_diff = min(left_diff, right_diff);
                ll max_diff = max(left_diff, right_diff);

                // now inclding nums[i]
                /*
                total subarrays of length 1 = 1
                of length 2= 2 
                of length 3 = 3
                of length min_diff = min_diff

                so sum of all these occurences is (min_diff)(min_diff+1)/2

                so basically no of subarrays for the range of length[1, min_diff, max_diff, k]

                from 1 to min_diff -> increasing by 1
                from min_diff to max_diff -> min_diff (constant)
                from max_diff to min(k, min_diff+max_diff-1) -> again decreasing by 1
                
                */

                ans += 1ll * ((min_diff * (min_diff + 1)) >> 1) * nums[i];
                ans += 1ll * (min(k, max_diff+min_diff-1) - min_diff) * min_diff * nums[i];

                ll diff = min(k, max_diff+min_diff-1) - max_diff;
                ans -= 1ll * ((diff * (diff + 1)) >> 1) * nums[i];
            }
        }

        {
           // stack
            vector<ll> s;
            // to store the indices of the elements greater than your element in the nearest left and in the nearest right
            vector<ll> left(n, -1), right(n, n);
            
            for(ll i = 0; i < n; i++){
                // for the previous elements of stack is curr element is >= than it then it will be the greater element in right for them
                while(!s.empty() && nums[s.back()] >= nums[i]){
                    right[s.back()] = i;
                    s.pop_back();
                }
                
                // now if the stack is not empty then it contains the element > curr element and for the left[i] for curr element
                if(!s.empty()) left[i] = s.back();

                s.push_back(i);
            }


            for(ll i = 0; i < n; i++){
                // standing at nums[i] subarray of size at most k and where the nums[i] will be maximum
                // to maintain the window of at most k elements from both left and right
                left[i] = max(left[i], i-k);
                right[i] = min(right[i], i+k);

                // in this range the nums[i] is the maximum 

                ll left_diff = i - left[i];
                ll right_diff = right[i] - i;
                ll min_diff = min(left_diff, right_diff);
                ll max_diff = max(left_diff, right_diff);

                // now inclding nums[i]
                /*
                total subarrays of length 1 = 1
                of length 2= 2 
                of length 3 = 3
                of length min_diff = min_diff

                so sum of all these occurences is (min_diff)(min_diff+1)/2

                so basically no of subarrays for the range of length[1, min_diff, max_diff, k]

                from 1 to min_diff -> increasing by 1
                from min_diff to max_diff -> min_diff (constant)
                from max_diff to min(k, min_diff+max_diff-1) -> again decreasing by 1
                
                */

                ans += 1ll * ((min_diff * (min_diff + 1)) >> 1) * nums[i];
                ans += 1ll * (min(k, max_diff+min_diff-1) - min_diff) * min_diff * nums[i];

                ll diff = min(k, max_diff+min_diff-1) - max_diff;
                ans -= 1ll * ((diff * (diff + 1)) >> 1) * nums[i];
            } 
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