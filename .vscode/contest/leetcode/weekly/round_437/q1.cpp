#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            int count = 1;
            for(int j = 1; j <= k-1; j++){
                if(s[i] != s[i+j]){
                    break;
                }
                count++;
            }
            if(count == k){
                bool check = true;
                if(i-1 >= 0 && s[i-1] == s[i]) check = false;
                if(i+k < n && s[i+k-1] == s[i+k]) check = false;
                if(check) return true;
            }
        }

        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "abc";
    int k = 2;
    cout << sol.hasSpecialSubstring(s, k);

    return 0;
}