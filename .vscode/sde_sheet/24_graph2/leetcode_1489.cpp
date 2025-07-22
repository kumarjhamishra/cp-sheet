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

/*
weighted undirected connected graph
n nodes 0 to n-1
edges[i] = [ai, bi, weighti]

in the MST find all the critical and pseudo-critical edges
Critical edge - whose deletion from graph would increase the mst weight
Pseudo-critical edge - can appear in some MST's but not all
*/

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
        // base case
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v){
        u = findParent(u), v = findParent(v);

        if(u == v) return;

        if(rank[u] >= rank[v]){
            rank[u] += rank[v];
            parent[v] = u;
        }
        else{
            rank[v] += rank[u];
            parent[u] = v;
        }
    }

    int getRank(int u){
        return rank[u];
    }
};

class Solution {
private:
    int n;
    int performKruskal(vector<tiii>& edges, vi& mandatoryEdge){

        DisjointSet ds(n);
        int sum = 0;

        // if it is mandatory to include this edge
        // and after this edge perform normal mst algo
        if(!mandatoryEdge.empty()){
            int u = mandatoryEdge[0], v = mandatoryEdge[1], w = mandatoryEdge[2];
            ds.unionByRank(u, v);
            sum += w;
        }

        
        sort(edges.begin(), edges.end());

        for(tiii i : edges){
            int w = get<0>(i);
            int u = get<1>(i);
            int v = get<2>(i);
            
            if(ds.findParent(u) == ds.findParent(v)) continue;

            ds.unionByRank(u, v);
            sum += w;
        }

        // check if all the nodes are connected in a single component or not
        for(int node = 0; node < n; node++){
            if(ds.getRank(node) == n){
                return sum;
            }
        }

        return INT_MAX;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        this->n = n;


        vector<tiii> edges1;

        // 1. do the normal mst
        for(vi i : edges){
            int u = i[0], v = i[1], w = i[2];
            edges1.push_back({w, u, v});
        }
        
        vi empty;
        int originalSum = performKruskal(edges1, empty);

        // 2. find all the critical edges
        // by excluding edge one by one and then checking mst weight sum
        vector<tiii> edges2;
        unordered_set<int> criticalEdges;
        for(int i = 0; i < edges.size(); i++){
            for(int j = 0; j < edges.size(); j++){
                if(edges[j] == edges[i]) continue;

                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                edges2.push_back({w, u, v});
            }

            int newSum = performKruskal(edges2, empty);
            if(newSum > originalSum){
                criticalEdges.insert(i);
            }
            edges2 = {};
        }

        // now we have all the ciritcal edges 
        // and need to find non critical edges

        //3. include the edges one by one and then perform mst with it and compare weight sum
        vector<tiii> edges3 = edges1;
        vector<int> nonCriticalEdges;
        for(int i = 0; i < edges.size(); i++){
            int newSum = performKruskal(edges3, edges[i]);
            // this edge part of mst and not a critical edge - means non critical edge
            if(newSum == originalSum && !criticalEdges.count(i)){
                nonCriticalEdges.push_back(i);
            }
        }

        vector<int> critical(criticalEdges.begin(), criticalEdges.end());

        vvi ans;
        ans.push_back(critical);
        ans.push_back(nonCriticalEdges);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int n = 6;
    vvi edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
    vvi ans = sol.findCriticalAndPseudoCriticalEdges(n, edges);
    for(int i = 0; i < ans[0].size(); i++){
        cout << ans[0][i] << " ";
    }
    cout << endl;
    for(int i = 0; i < ans[1].size(); i++){
        cout << ans[1][i] << " ";
    }
}