#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <functional>

#define loop(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define pii pair<int, int>
#define int long long

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<vector<int>> Matrix;


class Solution
{
public:
    vector<int> findCoins(vector<int> &numWays)
    {
        int n = numWays.size();
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> coins;

        for (int c = 1; c <= n; c++)
        {
            if (dp[c] > numWays[c - 1])
            {
                return {};
            }
            else if (dp[c] == numWays[c - 1])
            {
                continue;
            }
            else
            {
                if (numWays[c - 1] == dp[c] + 1)
                {
                    coins.push_back(c);
                    for (int i = c; i <= n; i++)
                    {
                        dp[i] += dp[i - c];
                    }
                }
                else
                {
                    return {};
                }
            }
        }

        return coins;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> numWays = {1, 2, 3, 4, 15};
    vector<int> ans = sol.findCoins(numWays);
    for (int i : ans)
        cout << i << " ";

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