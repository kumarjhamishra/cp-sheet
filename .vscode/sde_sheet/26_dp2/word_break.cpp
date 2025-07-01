// const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
// const auto __ = []() {
//     struct ___ {
//         static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//     };
//     std::atexit(&___::_);
//     return 0;
// }();

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
private:
    int n;
    vi dp;
    bool f(int i, string &s, unordered_set<string> &st){
        // base cae
        if(i == n) return true;

        if(dp[i] != -1) return dp[i];

        bool ans = false;
        string segment;
        for(int j = i; j < n; j++){
            segment.push_back(s[j]);
            if(st.count(segment)){
                ans = f(j+1, s, st);
            }
            if(ans) return dp[i] = true;
        }

        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp.resize(n, -1);
        return f(0, s, st);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout << sol.wordBreak(s, wordDict);

    return 0;
}

