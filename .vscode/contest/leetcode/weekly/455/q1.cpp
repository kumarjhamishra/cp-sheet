#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<bool> isPrime(101, true);

        isPrime[0] = isPrime[1]= false;
        for(int i = 2; i <= 100; i++){
            for(int j = i*i; j <= 100; j += i){
                isPrime[j] = false;
            }
        }

        vector<int> freq(101, 0);
        for(int i : nums) freq[i]++;

        for(int i : freq){
            if(i != 0 && isPrime[i]) return true;
        }

        return false;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {2,2,2,4,4};
    cout << sol.checkPrimeFrequency(nums);

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