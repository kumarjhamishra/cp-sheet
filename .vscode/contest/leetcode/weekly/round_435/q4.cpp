// reference solution - https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/solutions/6360587/c-python-prefix-sum-math-explanation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();

        // numbers can be from 0 to 4 which is total 5
        vector<vector<int>> pre(5, vector<int>(n, 0)), closest_right(5, vector<int>(n, n));
        for(int num = 0; num < 5; num++){

            for(int i = 0; i < n; i++){
                int curr_num = s[i] - '0';
                pre[num][i] = (num == curr_num);
                if(i > 0) pre[num][i] += pre[num][i-1];
            }

            for(int i = n-1; i >= 0; i--){
                int curr_num = s[i] - '0';
                if(i < n-1) closest_right[num][i] = closest_right[num][i+1];
                if(num == curr_num) closest_right[num][i] = i;
            }
        }

        int maxDiff = INT_MIN;

        auto f = [&](int odd, int even) -> int {
            vector<vector<vector<int>>> suff(2, vector<vector<int>>(2, vector<int>(n, INT_MIN)));

            for(int i = 0; i < n; i++){
                int odd_parity = pre[odd][i] % 2;
                int even_parity = pre[even][i] % 2;

                if(pre[odd][i] > 0 && pre[even][i] > 0) suff[odd_parity][even_parity][i] = (pre[odd][i] - pre[even][i]);
            }

            for(int odd_parity = 0; odd_parity < 2; odd_parity++){
                for(int even_parity = 0; even_parity < 2; even_parity++){
                    for(int i = n-2; i >= 0; i--){
                        suff[odd_parity][even_parity][i] = max(suff[odd_parity][even_parity][i], suff[odd_parity][even_parity][i+1]);
                    }
                }
            }

            for(int start_i = 0; start_i < n; start_i++){
                int initial_end_i = start_i + k - 1;
                if(initial_end_i >= n) break;

                int odd_before_i = (start_i == 0 ? 0 : pre[odd][start_i-1]);
                int even_before_i = (start_i == 0 ? 0 : pre[even][start_i-1]);

                int good_odd_parity = (odd_before_i + 1) % 2;
                int good_even_parity = (even_before_i) % 2;

                int final_end_i = max({initial_end_i, closest_right[odd][start_i], closest_right[even][start_i]});
                if(final_end_i >= n) continue;

                int val = suff[good_odd_parity][good_even_parity][final_end_i];
                if(val == INT_MIN) continue;

                maxDiff = max(maxDiff, val - odd_before_i + even_before_i);
            }

            return maxDiff;
        };

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(i != j) f(i, j);
            }
        }

        return maxDiff;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "110";
    int k = 3;
    Solution sol;
    cout << sol.maxDifference(s, k);

    return 0;
}