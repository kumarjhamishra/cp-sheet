#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    set<string> uniquePalindromes;
    unordered_map<string, bool> visited;
    int n, k;

    void generatePalindromes(string pal, int i, vector<int> freq){
        // base case
        if(uniquePalindromes.size() == k) return ;

        if(i == (n-1)/2){
            // find char whose frequency has not became 0
            char lastChar;
            for(int idx = 0; idx < 26; idx++){
                if(freq[idx] != 0){
                    lastChar = ('a' + idx);
                    break;
                }
            }
            pal[i] = lastChar, pal[n-i-1] = lastChar;
            if(!visited[pal]){
                uniquePalindromes.insert(pal);
                visited[pal] = true;
            } 
            return ;
        }

        for(int idx = 0; idx < 26; idx++){
            // char with freq 1 will only be placed as middle element
            if(freq[idx] > 1){
                pal[i] = ('a' + idx), pal[n-i-1] = ('a' + idx);
                freq[idx] -= 2;
                generatePalindromes(pal, i+1, freq);
                freq[idx] += 2;
            }
        }
    }
public:
    string smallestPalindrome(string s, int k)
    {
        vector<int> freq(26, 0);
        int n = s.size();
        this->n = n;
        this->k = k;
        for(int i = 0; i < n; i++) freq[s[i] - 'a']++;
        
        string pal(n, '0');
        generatePalindromes(pal, 0, freq);

        if(uniquePalindromes.size() >= k){
            auto it = uniquePalindromes.begin();
            advance(it, k-1);
            return *it;
        }
        return "";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "plykxwklfbbflkwxkylp";
    int k = 570393;
    cout << sol.smallestPalindrome(s, k);
    return 0;
}