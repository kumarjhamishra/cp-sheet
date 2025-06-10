#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<vector<ll>>> vvvi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;

class Solution
{
private:
    ll f(int i, int cntTrans, int option, vector<int> &prices, vvvi &dp, int &n, int &k){
        // base cases
        if(cntTrans == 2*k){
            return 0ll;
        }

        ll maxProfit = 0;
        if(i == n-1){
        
            if(option == 0){
                // we need to buy and close the transaction
                maxProfit = -prices[i];
            }
            else if(option == 1){
                // then we need to sell and close the transcation
                maxProfit = prices[i];
            }
            else{
                // have both option
                // but can't start a new transaction bcoz then that won't be compelted
                maxProfit = 0;
            }
            return maxProfit;
        }

        if(dp[i][cntTrans][option] != -1) return dp[i][cntTrans][option];


        if(option == 0){
            // can only buy

            ll buy = 0, notBuy = 0;
            
            // if we decided to buy
            buy = -prices[i] + f(i+1, cntTrans+1, 2, prices, dp, n, k);
            notBuy = 0 + f(i+1, cntTrans, 0, prices, dp, n, k);

            maxProfit = max(buy, notBuy);
        }
        else if(option == 1){
            // can only sell
            ll sell = 0, notSell = 0;
            
            // if we decided to buy
            sell = prices[i] + f(i+1, cntTrans+1, 2, prices, dp, n, k);
            notSell = 0 + f(i+1, cntTrans, 1, prices, dp, n, k);

            maxProfit = max(sell, notSell);
        }

        // option 2
        else{
            // can buy or sell 
            ll buy = 0, nothing = 0, sell = 0;

            // if bought
            buy = -prices[i] + f(i+1, cntTrans+1, 1, prices, dp, n, k);

            // if sell
            sell = prices[i] + f(i+1, cntTrans+1, 0, prices, dp, n, k);

            // if do nothing
            nothing = 0 + f(i+1, cntTrans, 2, prices, dp, n, k);

            maxProfit = max({buy, sell, nothing});

        }

        return dp[i][cntTrans][option] = maxProfit;

    }
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        
        // 3 options - 0 -> can only buy, 1 -> can only sell, 2 -> can buy or can sell
        vvvi dp(n, vvi(2*k+1, vi(3, -1)));

        return f(0, 0, 2, prices, dp, n, k);
    }
};

int main()
{
    vector<int> prices = {12,16,19,19,8,1,19,13, 9};
    int k = 3;
    Solution sol;
    cout << sol.maximumProfit(prices, k);

    return 0;
}