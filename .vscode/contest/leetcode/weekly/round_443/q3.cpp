#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        // the dp state {i, j, k} represents the cost of painting house with length i from both the ends of row and from left side current house with color j and from right side current house with color k

        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(3, vector<ll>(3, LLONG_MAX)));
        // initialising the minimum cost with infinity

        // handling base case
        // i = 0 means first and last house so the cost will be cost[j] + cost[k] for j != k to saatisfy condition

        for(ll j = 0; j < 3; j++){
            for(ll k = 0; k < 3; k++){
                if(j != k) dp[0][j][k] = cost[0][j] + cost[n-1][k];
            }
        }
        

        // bcoz we are taking the length from both left and right side therefore we will only iterate to n/2
        for(ll i = 1; i < n/2; i++){
            for(ll j = 0; j < 3; j++){
                for(ll k = 0; k < 3; k++){
                    // till the length i from both the ends of row the curr house i and n-i-1 should be of diff colors
                    if(j != k){
                        
                        // the dp state for dp[i][j][k] will be cost[i][j] + cost[n-i-1][k] (j != k) + dp[i-1][nj][nk]
                        // where nj != j and nk != k bcoz adjacent colors can't be same and nj != nk coz they will be at the same distance from both the ends of row

                        for(ll nj = 0; nj < 3; nj++){
                            for(ll nk = 0; nk < 3; nk++){
                                if(nj != j && nk != k && nj != nk){
                                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][nj][nk]);

                                }
                            }
                        }
                        
                        dp[i][j][k] += cost[i][j] + cost[n-i-1][k];
                    }
                }
                
            }
            
        }
        

        // the final ans will be stored in n/2the cell for all colors j and k where j != k
        ll ans = LLONG_MAX;
        for(ll j = 0; j < 3; j++){
            for(ll k = 0; k < 3; k++){
                if(j != k) ans = min(ans, dp[n/2 - 1][j][k]);
                
            }
        }

        return ans;
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