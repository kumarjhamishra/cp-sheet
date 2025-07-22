/*
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef tuple<int, int, int> tiii;
typedef vector<vector<pii>> vvpii;
typedef vector<vvpii> vvvpii;

class DisjointSet{
private: 
    vi rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 1);
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int u){
        if(u == parent[u]) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v){
        u = findParent(u), v = findParent(v);

        if(u == v) return ;

        if(rank[u] >= rank[v]){
            rank[u] += rank[v];
            parent[v] = u;
        }
        else{
            rank[v] += rank[u];
            parent[u] = v;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tiii> edges;

        int n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                int u = i, v = j;
                edges.push_back({w, u, v});
            }
        }

        sort(edges.begin(), edges.end());

        int sum = 0;
        DisjointSet ds(n);

        for(tiii i : edges){
            int w = get<0>(i);
            int u = get<1>(i);
            int v = get<2>(i);
            
            if(ds.findParent(u) == ds.findParent(v)) continue;

            ds.unionByRank(u, v);
            sum += w;
        }

        return sum;

    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vvi points = {{3,12},{-2,5},{-4,1}};
    cout << sol.minCostConnectPoints(points);
    return 0;
}