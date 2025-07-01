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
typedef vector<vector<int>> vvi;

class Solution {
private:
    vvi dp;
    int f(int i, int j, int &n1, int &n2, string& s1, string& s2){
        // base case
        if(i == n1 || j == n2) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int len = 0;
        if(s1[i] == s2[j]) len = 1 + f(i+1, j+1, n1, n2, s1, s2);
        else len = max(f(i+1, j, n1, n2, s1, s2), f(i, j+1, n1, n2, s1, s2));
        return dp[i][j] = len;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        dp.resize(n1, vi(n2, -1));
        return f(0, 0, n1, n2, text1, text2);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string text1 = "abcde", text2 = "ace";
    cout << sol.longestCommonSubsequence(text1, text2);
    return 0;
}