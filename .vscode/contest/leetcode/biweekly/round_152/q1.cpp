#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        set<int> st;
        int n = digits.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(digits[i] != 0 && i != j && j != k && i != k && digits[k] % 2 == 0){
                        st.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                    }
                }
            }
        }

        return st.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }

    return 0;
}