#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int idx, int prevChar, int len, string& s){
        // base case
        if(idx == n){
            // valid block has been formed
            if(len == 3){
                // now more blocks can be made
                return 0;
            }

            return INT_MAX;
        }

        if(dp[idx][prevChar][len] != -1) return dp[idx][prevChar][len];

        int minCost = INT_MAX;
        // case when already a previous block is running
        // try to continue the same character
        if(prevChar != 26){
            int nextMinCost = solve(idx+1, prevChar, min(len+1, 3), s);
            // if continuing with the prev character is possible to make a good string
            if(nextMinCost != INT_MAX){
                minCost = min(minCost, abs(s[idx] - ('a' + prevChar)) + nextMinCost);
            }
        }

        // if no previous character is choosen or already the length of previous block is 3
        if(prevChar == 26 || len == 3){
            // try to compute the min cost for every character
            for(int i = 0; i < 26; i++){
                int nextMinCost = solve(idx+1, i, 1, s);
                if(nextMinCost != INT_MAX){
                    minCost = min(minCost, abs(s[idx] - ('a' + i)) + nextMinCost);
                }
            }
        }

        return dp[idx][prevChar][len] = minCost;
    }

    void build(int idx, int prevChar, int len, string& s, string& ans){
        // base case
        if(idx ==  n) return ;

        // want to choose that character whose operations is minimum
        int ch = 26, operations = INT_MAX;

        // try with the previous character
        if(prevChar != 26){
            int nextOperations = solve(idx+1, prevChar, min(len+1, 3), s);

            if(nextOperations != INT_MAX && operations > abs(s[idx] - ('a' + prevChar)) + nextOperations){
                operations = abs(s[idx] - ('a' + prevChar)) + nextOperations;
                ch = prevChar;
            }
        }

        // if previous character is not present or the previous block length is already 3
        if(prevChar == 26 || len == 3){
            for(int i = 0; i < 26; i++){
                int nextOperations = solve(idx+1, i, 1, s); 
                if(nextOperations != INT_MAX){
                    // operations = abs(s[idx] - ('a' + i)) + nextOperations;
                    // ch = i;

                    if(operations > abs(s[idx] - ('a' + i)) + nextOperations){
                        operations = abs(s[idx] - ('a' + i)) + nextOperations;
                        ch = i;
                    }
                    else if(operations == abs(s[idx] - ('a' + i)) + nextOperations){
                        ch = min(ch, i);
                    }
                }
            }
        }

        ans[idx] = 'a' + ch;

        // calls to build the next char
        if(prevChar == ch){
            build(idx+1, prevChar, min(len+1, 3), s, ans);
        }
        else build(idx+1, ch, 1, s, ans);
    }

public:
    string minCostGoodCaption(string caption) {
        n = caption.size();
        if(n < 3) return "";
        
        // dp has 3 states - {idx, prev char , length of prev block}
        // prev char can be from a to z and 26 to represent no previous character and prev block length can be 1 for length 1, 2 for length 2 and 3 for length >= 3

        dp.resize(n, vector<vector<int>>(27, vector<int>(4, -1)));

        // function to calculate the minimum operation to convert caption into a good string
        // 26 -> means no prev character initially and initially length of block is 0
        int minOperation = solve(0, 26, 0, caption);

        if(minOperation == INT_MAX) return "";

        // build the lexographically smallest good string
        string ans(n, 'a');
        build(0, 26, 0, caption, ans);
        return ans;
        
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution s;
    string caption = "oweaxihc";
    cout << s.minCostGoodCaption(caption) << endl;
    return 0;
}