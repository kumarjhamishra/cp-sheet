#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // 1. calculate in advance whether a number is prime or not
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxi+1, true);

        // 0 and 1 are not prime
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i <= maxi; i++){
            // mark all the multiples of prime as non prime
            if(maxi - i <= i) continue;
            for(int j = i * i; j <= maxi; j += i){
                isPrime[j] = false;
            }
        }

        // multiset will store the primes in sorted manner (also stores duplicates)
        multiset<int> s; // to store the prime element
        // deque gives access to push and pop from both front and back
        deque<int> dq; // to store the indices

        int l = 0, r = 0, count = 0;
        for(int r = 0; r < n; r++){
            // 2. if nums[r] is prime store it in multiset and it's index in deque
            if(isPrime[nums[r]]){
                s.insert(nums[r]);
                dq.push_back(r);
            }

            // 3. shrink the window from left if it's violates the condition that max prime - min prime <= k
            while(!s.empty() && *s.rbegin() - *s.begin() > k){
                if(isPrime[nums[l]]){
                    s.erase(s.find(nums[l])); // this will only delete one occurence of nums[l]
                    dq.pop_front();
                }
                l++;
            }

            // 4. count the subarrays if the current window has more than equal to 2 primes -> coz they now definitely satisfy the diff condition
            if(dq.size() >= 2){
                // 5. from the position of l till the 2nd last prime from right, all will form a valid subarray with the last prime from left, satisfying the diff condition
                int last = dq.back();
                dq.pop_back();
                int secondLast = dq.back();
                dq.pop_back();

                count += secondLast - l + 1;

                // 6. now again the place the back the last second last in dq for next iterations
                dq.push_back(secondLast);
                dq.push_back(last);
            }
        }

        return count;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {2,3,5,7};
    int k = 3;
    cout << sol.primeSubarray(nums, k);

    return 0;
}

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