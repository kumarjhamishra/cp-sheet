#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        
        if(k == 0) return true;
        vector<int> freq(26, 0);
        int countUnique = 0, n = s.size(), notCountUnique;

        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
            if(i-1 >= 0 && freq[s[i] - 'a'] > 1 && s[i] == s[i-1]){
                freq[s[i] - 'a']--;
            } 
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] == 1) countUnique++;
            
        }

        //cout << "countUnique: " << countUnique << endl;
        return countUnique >= k && countUnique >= 1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "gyye";
    int k = 3;
    Solution sol;
    cout << sol.maxSubstringLength(s, k);

    return 0;
}