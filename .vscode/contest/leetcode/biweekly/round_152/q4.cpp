#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pii>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], len = e[2];
            adj[u].emplace_back(v, len);
            adj[v].emplace_back(u, len);
        }

        vector<ll> depth_sum(n, 0);
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(0);
        parent[0] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& [v, len] : adj[u]) {
                if (v != 0 && parent[v] == -1) {
                    parent[v] = u;
                    depth_sum[v] = depth_sum[u] + len;
                    q.push(v);
                }
            }
        }

        vector<int> path;
        unordered_map<int, int> freq;
        int start = 0;
        int duplicate_count = 0;
        ll max_sum = 0;
        int min_nodes = INT_MAX;

        function<void(int, int)> dfs = [&](int u, int p) {
            path.push_back(u);
            int val = nums[u];
            freq[val]++;
            if (freq[val] == 2) {
                duplicate_count++;
            }

            while (duplicate_count > 1) {
                int start_val = nums[path[start]];
                freq[start_val]--;
                if (freq[start_val] == 1) {
                    duplicate_count--;
                }
                start++;
            }

            ll current_sum = depth_sum[u];
            if (start > 0) {
                current_sum -= depth_sum[path[start - 1]];
            }
            int current_nodes = path.size() - start;

            if (current_sum > max_sum) {
                max_sum = current_sum;
                min_nodes = current_nodes;
            } else if (current_sum == max_sum) {
                if (current_nodes < min_nodes) {
                    min_nodes = current_nodes;
                }
            }

            for (auto& [v, len] : adj[u]) {
                if (v != p) {
                    dfs(v, u);
                }
            }

            path.pop_back();
            freq[val]--;
            if (freq[val] == 1) {
                duplicate_count--;
            } else if (freq[val] == 0) {
                freq.erase(val);
            }
        };

        dfs(0, -1);

        return { (int)max_sum, min_nodes };
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }

    return 0;
}