#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution
{
private:
    const int mod = 1e9 + 7;
    int ans = 0;

    bool check(int n, int freq){
        while(n){
            int x = n % 10;
            // 2 freq
            if(freq & 1 << x) return 0;
            freq |= 1 << x;
            n /= 10;
        }
        return 1;
    }

    int f(int i, vector<int> &toGive, int freq, vvi &dp){
        // base case
        if(i >= toGive.size()) return 0;

        if(dp[i][freq] != -1) return dp[i][freq];

        // not taking the values at current node
        int notTake = f(i+1, toGive, freq, dp);

        int take = 0;
        // can only take when maintaining the frequency
        if(check(toGive[i], freq)){
            int newFreq = freq;
            int x = toGive[i];
            while(x){
                int y = x % 10;
                newFreq |= 1 << y;
                x /= 10;
            }
            take = toGive[i] + f(i+1, toGive, newFreq, dp);
        }

        return dp[i][freq] = max(take, notTake);

    }

    vector<int> dfs(int node, vector<int> &v, vector<int> &vals, unordered_map<int, vector<int>> &adj){
        vector<int> toGive;

        for(int ngbr : adj[node]){
            // go to it's child
            vector<int> child = dfs(ngbr, v, vals, adj);
            // store the child's vector for current node processing
            toGive.insert(toGive.end(), child.begin(), child.end());
        }

        // now push the current node
        toGive.push_back(vals[node]);

        vvi dp(toGive.size() + 1, vector<int>(1025, -1));
        
        // ans for current node - maximum beauty score
        int temp = f(0, toGive, 0, dp);
        ans += temp;
        ans %= mod;
        return toGive;
    }

public:
    int goodSubtreeSum(vector<int> &vals, vector<int> &par)
    {
        int n = vals.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            adj[par[i]].push_back(i);
        }

        vector<int> v;
        dfs(0, v, vals, adj);
        return ans;
    }
};

int main()
{

    return 0;
}