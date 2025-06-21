#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int evens = 0, odds = 0, n = nums.size();
        for(int i : nums){
            if(i % 2) odds++;
            else evens++;
        }

        if(n % 2 && abs(evens - odds) > 1) return -1;
        if(n % 2 == 0 && evens - odds != 0) return -1;

        
    }
};

    int
    main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Solution sol;
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