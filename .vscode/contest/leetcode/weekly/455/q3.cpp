#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<int> pilvordanq = cost;

        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> in_time(n, 0), out_time(n, 0);
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);
        vector<long long> root_sum(n, 0);
        vector<vector<int>> children(n);
        vector<int> next_idx(n, 0);
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(0);
        parent[0] = -1;
        depth[0] = 0;
        root_sum[0] = cost[0];
        in_time[0] = 0;
        int time_counter = 1;

        while (!st.empty()) {
            int u = st.top();
            if (!visited[u]) {
                visited[u] = true;
            }
            if (next_idx[u] < graph[u].size()) {
                int v = graph[u][next_idx[u]++];
                if (v == parent[u]) {
                    continue;
                }
                parent[v] = u;
                depth[v] = depth[u] + 1;
                root_sum[v] = root_sum[u] + cost[v];
                children[u].push_back(v);
                in_time[v] = time_counter++;
                st.push(v);
            } else {
                out_time[u] = time_counter - 1;
                st.pop();
            }
        }

        vector<bool> is_leaf(n, false);
        long long max_sum = 0;
        for (int i = 0; i < n; i++) {
            if (children[i].size() == 0) {
                is_leaf[i] = true;
                if (root_sum[i] > max_sum) {
                    max_sum = root_sum[i];
                }
            }
        }

        vector<long long> max_leaf(n, 0);
        vector<int> deg(n, 0);
        for (int i = 0; i < n; i++) {
            deg[i] = children[i].size();
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            if (parent[u] != -1) {
                deg[parent[u]]--;
                if (deg[parent[u]] == 0) {
                    q.push(parent[u]);
                }
            }
        }
        for (int i = 0; i < order.size(); i++) {
            int u = order[i];
            if (is_leaf[u]) {
                max_leaf[u] = root_sum[u];
            } else {
                max_leaf[u] = 0;
                for (int v : children[u]) {
                    if (max_leaf[v] > max_leaf[u]) {
                        max_leaf[u] = max_leaf[v];
                    }
                }
            }
        }

        vector<bool> marked(n, false);
        for (int i = 0; i < n; i++) {
            if (max_leaf[i] == max_sum) {
                marked[i] = true;
            }
        }

        vector<int> highest_unmarked(n, -1);
        queue<int> q_bfs;
        q_bfs.push(0);
        if (!marked[0]) {
            highest_unmarked[0] = 0;
        } else {
            highest_unmarked[0] = -1;
        }
        while (!q_bfs.empty()) {
            int u = q_bfs.front(); q_bfs.pop();
            for (int v : children[u]) {
                if (highest_unmarked[u] != -1) {
                    highest_unmarked[v] = highest_unmarked[u];
                } else {
                    if (!marked[v]) {
                        highest_unmarked[v] = v;
                    } else {
                        highest_unmarked[v] = -1;
                    }
                }
                q_bfs.push(v);
            }
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            if (is_leaf[i] && root_sum[i] < max_sum) {
                pq.push({depth[i], i});
            }
        }

        vector<int> fenw(n+2, 0);
        auto fenw_update = [&](int index, int delta) {
            int i = index + 1;
            while (i <= n+1) {
                fenw[i] += delta;
                i += i & -i;
            }
        };

        auto fenw_query = [&](int index) -> int {
            int i = index + 1;
            int s = 0;
            while (i > 0) {
                s += fenw[i];
                i -= i & -i;
            }
            return s;
        };

        int count = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (fenw_query(in_time[u]) > 0) {
                continue;
            }
            int v = highest_unmarked[u];
            if (v == -1) {
                v = u;
            }
            fenw_update(in_time[v], 1);
            if (out_time[v] + 1 < n) {
                fenw_update(out_time[v] + 1, -1);
            }
            count++;
        }

        return count;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0,4},{0,1},{1,2},{1}};
    vector<int> cost = {5,1,4};
    cout << sol.minIncrease(n, edges, cost);

    return 0;
}