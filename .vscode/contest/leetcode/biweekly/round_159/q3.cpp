#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        // precomputing all the primes
        vector<int> isPrime(5*1e4 + 1, true);

        // 0 and 1 are not prime
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i < 5 * 1e4 + 1; i++){
            if(isPrime[i]){
                for(int j = i*i; j < 5 * 1e4 + 1; j += i){
                    isPrime[j] = false;
                }
            }
        }

        int s = 0, count = 0, countPrime = 0, n = nums.size();
        deque<int> minD, maxD;

        for(int e = 0; e < n; e++){
            if(isPrime[nums[e]]){
                while(!minD.empty() && nums[e] < minD.back()) minD.pop_back();

                minD.push_back(nums[e]);

                while(!maxD.empty() && nums[e] > maxD.back()) maxD.pop_back();

                maxD.push_back(nums[e]);

                countPrime++;
            }

            // shrinking from left
            while(!minD.empty() && !maxD.empty() && maxD.front() - minD.front() > k){
                if(isPrime[s]){
                    if(nums[s] == minD.front()) minD.pop_front();
                    if(nums[s] == maxD.front()) maxD.pop_front();
                    countPrime--;
                }
                s++;
            }

            if (countPrime >= 2) {
                
                int left = s;
                int right = e;
                int validStart = left;

                
                int tmpPrimeCount = 0;
                for (int i = e; i >= s; --i) {
                    if (isPrime[nums[i]]) ++tmpPrimeCount;
                    if (tmpPrimeCount >= 2) ++count;
                }
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