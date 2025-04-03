#include <bits/stdc++.h>
using namespace std;

// reference video - https://www.youtube.com/watch?v=ew_zmRf-jQ0

class Solution
{
private:
   
public:
    int longestPalindrome(string s, string t)
    {
        int ns = s.size(), nt = t.size();
        /*step 1 : compute the length of longest palindrome starting from index i for string s
        and compute the longest palindrome ending at j for string t
        
        s[i...j] is a palindrome if s[i] == s[j] and s[i+1....j-1] is also a palindrome
        */

        // for s
        vector<vector<bool>> dp_s(ns, vector<bool>(ns, false));

        /*
        if j = i dp_s[i][i] = true
        j = i + 1 dp_s[i][j] = s[i] == s[i+1]
        */

        // maximum length of palindrome in s starting at i
        vector<int> maxs(ns);
        // also store the maximum length of palindrome from any string
        int maxPalindromeLength = 0;
        for(int i = ns-1; i >= 0; i--){
            for(int j = i; j < ns; j++){
                dp_s[i][j] = (i == j) || (j == i+1 && s[i] == s[j]) || (dp_s[i+1][j-1] && s[i] == s[j]);
                if(dp_s[i][j]){
                    maxs[i] = max(maxs[i], j-i+1);
                    
                }
            }
        }

        // for string t the maximum length of palindrome ending at index i
        vector<vector<bool>> dp_t(nt, vector<bool>(nt, false));
        vector<int> maxt(nt);

        for(int i = nt-1; i >= 0; i--){
            for(int j = i; j < nt; j++){
                dp_t[i][j] = (i == j) || (j == i+1 && t[i] == t[j]) || (dp_t[i+1][j-1] && t[i] == t[j]);
                if(dp_t[i][j]){
                    maxt[i] = max(maxt[i], j-i+1);
                    maxPalindromeLength = max(maxPalindromeLength, j-i+1);
                }
            }
        }

        vector<vector<int>> dp(ns, vector<int>(nt, 0));
        // if(s[i] == t[j]) dp[i][j] = 2 + dp[i-1][j+1]

        for(int i = 0; i < ns; i++){
            for(int j = nt-1; j >= 0; j--){
                if(s[i] == t[i]){
                    if(i > 0 && j < nt-1){
                        dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 2);
                    }
                    else dp[i][j] = 2;

                    int extra = 0;
                    if(i + 1 < ns) extra = max(extra, maxs[i+1]);
                    if(j-1 >= 0) extra = max(extra, maxt[j-1]);
                    maxPalindromeLength = max(maxPalindromeLength, dp[i][j] + extra);
                }
            }
        }

        return maxPalindromeLength;

    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "p", t = "krykpr";
    cout << sol.longestPalindrome(s, t) << endl;

    return 0;
}