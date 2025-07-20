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

        if(u == v){
            // nodes are already connected, extra edge
            return ;
        }

        // u is parent of v
        rank[u] += rank[v];
        parent[v] = u;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // 1. find a node with 2 parents
        vi parent(n+1, 0), candidate1, candidate2;

        for(vi i : edges){
            int u = i[0], v = i[1];
            if(parent[v] != 0){
                // means this u is the 2nd parent of node u
                candidate1 = {parent[v], v};
                candidate2 = {u, v};

                //  in the whole tree, we could have only 1 such with 2 parents
                break;
            }
            else parent[v] = u;
        }

        // 2. use union find to detect a cycle
        DisjointSet ds(n);

        vi cycleEdge;
        for(vi i : edges){
            int u = i[0], v = i[1];
            if(i == candidate2){
                // skip it for now , coz we are testing cycle without this edge
                continue;
            }

            if(ds.findParent(u) == ds.findParent(v)){
                cycleEdge = i;
                break;
            }
            ds.unionByRank(u, v);
        }

        // 3. syntheize and return the answer

        // no 2 parent node - only problem is cycle
        if(candidate1.empty()) return cycleEdge;

        // 2 parent node is present
        // and graph also has a cycle
        if(!cycleEdge.empty()) return candidate1;

        // no cycle is present
        return candidate2;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vvi edges = {{2,1},{3,1},{4,2},{1,4}};
    sol.findRedundantDirectedConnection(edges);
    return 0;
}