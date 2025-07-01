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
    int f(int i, int j, string& w1, string& w2, int &n1, int &n2){
        // base cases
        if(j == n2){
            // when w2 ends - delete all the remaining characters of w1 if remaining
            return n1 - i;
        }
        if(i == n1){
            // w2 is remaining but w1 finished - insert all the remaining chars of w2 if remaining
            return n2 - j;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int operations = INT_MAX;
        if(w1[i] == w2[j]) operations = f(i+1, j+1, w1, w2, n1, n2);
        else{
            // insert
            operations = min(operations, 1 + f(i, j+1, w1, w2, n1, n2));
            //delete
            operations = min(operations, 1 + f(i+1, j, w1, w2, n1, n2));
            // replace
            operations = min(operations, 1 + f(i+1, j+1, w1, w2, n1, n2));
        }
        return dp[i][j] = operations;
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        dp.resize(n1, vi(n2, -1));
        return f(0, 0, word1, word2, n1, n2);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    string w1 = "horse", w2 = "ros";
    cout << sol.minDistance(w1, w2);

    return 0;
}