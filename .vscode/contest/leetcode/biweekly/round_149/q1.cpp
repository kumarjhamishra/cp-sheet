#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        vector<int> freq(101, 0);

        int n = s.size();
        for(int i = 0; i < n; i++){
            freq[s[i] - '0']++;
        }
        string validPair;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1] && s[i]-'0' == freq[s[i]-'0'] && s[i-1]-'0' == freq[s[i-1]-'0']){
                validPair.push_back(s[i-1]);
                validPair.push_back(s[i]);
                return validPair;
            }
        }

        return validPair;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        //solve();
    }

    return 0;
}