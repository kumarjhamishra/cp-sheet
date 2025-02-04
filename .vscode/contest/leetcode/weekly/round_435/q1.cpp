#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int oddMax = INT_MIN, oddMin = INT_MAX, evenMax = INT_MIN, evenMin = INT_MAX;

        vector<int> freq(26, 0);

        for(char &ch : s){
            freq[ch-'a']++;
        }

        int positiveDiff = INT_MIN, negativeDiff = INT_MAX;;
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 0 || freq[i] == 0) continue;
            for(int j = 0; j < 26; j++){
                if(freq[j] % 2 == 1 || freq[j] == 0) continue;

                positiveDiff = max(positiveDiff, freq[i] - freq[j]);
                
            }
        }

        //if(abs(negativeDiff) > positiveDiff && negativeDiff != INT_MAX) return negativeDiff;
        return positiveDiff;
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