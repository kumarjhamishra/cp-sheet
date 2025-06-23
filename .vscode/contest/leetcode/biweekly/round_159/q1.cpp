#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> evenIdx, oddIdx;
    int n;
    int calculateMinSwaps(bool isEven){
        vector<int> arr = evenIdx;
        if(!isEven) arr = oddIdx;

        int swaps = 0, j = 0;
        for(int i = 0; i < n;){
            swaps += abs(i - arr[j++]);
            i += 2;
        }

        return swaps;
    }
public:
    int minSwaps(vector<int> &nums)
    {
        n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] % 2) oddIdx.push_back(i);
            else evenIdx.push_back(i);
        }

        //cout << oddIdx.size() << " " << evenIdx.size() << endl;
        int countDiff = abs(evenIdx.size() - oddIdx.size());
        if(n % 2 && countDiff > 1) return -1;
        if(n % 2 == 0 && countDiff != 0) return -1;


        if(n % 2){
            return evenIdx.size() > oddIdx.size() ? calculateMinSwaps(true) : calculateMinSwaps(false);
        }

        return min(calculateMinSwaps(true), calculateMinSwaps(false));
    }
};

    int
    main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {4,5,6,8};
    cout << sol.minSwaps(nums);
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