#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int palindromeLength(string s){
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(s[i] != s[j]) return INT_MIN;
            i++, j--;
        }
        return s.size();
    }
public:
    int longestPalindrome(string s, string t)
    {
        int sn = s.size(), tn = t.size();
        if(sn < tn){

        }

        int longest = INT_MIN;
        for(int i = 0; i < sn; i++){
            string sub_s = "";
            for(int j = i; j < sn; j++){
                sub_s += s[j];
                //cout << "sub_s : " << sub_s << " ";
                longest = max(longest, palindromeLength(sub_s));
                for(int k = 0; k < tn; k++){
                    string sub_t = "";
                    for(int l = k; l < tn; l++){
                        sub_t += t[l];
                        //cout << "sub_t: " << sub_t << " ";
                        longest = max(longest, palindromeLength(sub_t));
                        //string sub_combined = sub_s + sub_t;
                        //cout << "sub_combined: " << sub_combined << endl;
                        longest = max(longest, palindromeLength(sub_s + sub_t));
                    }
                }
            }
        }

        return longest == INT_MIN ? 1 : longest;
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