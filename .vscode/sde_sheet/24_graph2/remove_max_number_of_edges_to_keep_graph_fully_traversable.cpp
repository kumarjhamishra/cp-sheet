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

struct tuple_hash{
    size_t operator()(const tuple<int, int, int>& t) const {
        int a = std::get<0>(t);
        int b = std::get<1>(t);
        int c = std::get<2>(t);

        return hash<int>()(a) ^ hash<int>()(b << 1) ^ hash<int>()(c << 2);
    }
};

class Solution {
private:
    unordered_set<tiii, tuple_hash> uniqueEdges;

    int prims(int n, vvi& edges){
        // for(vi i : edges){
        //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
        // }
        // make the adjency list
        vvpii adj(n+1);

        for(vi i : edges){
            int wght = i[0], u = i[1], v = i[2];
            //cout << wght << " " << u << " " << v << endl;
            // undirected graph
            adj[u].push_back({v, wght});
            adj[v].push_back({u, wght});
        }

        priority_queue<tiii, vector<tiii>, greater<tiii>> minHeap;
        vi visited(n+1, 0);

        // starting with node 1 and parent 0(null)
        minHeap.push({0, 1, 0});

        while(!minHeap.empty()){
            int wght = std::get<0>(minHeap.top());
            int node = std::get<1>(minHeap.top());
            int parent = std::get<2>(minHeap.top());

            minHeap.pop();

            if(visited[node]) continue;

            if(parent != 0){
                // to avoid duplicate entry
                int a = min(node, parent), b = max(node, parent);
                uniqueEdges.insert(std::make_tuple(wght, a, b));
            }

            visited[node] = 1;

            for(pii i : adj[node]){
                int ngbr = i.first, edgeWeight = i.second;
                if(!visited[ngbr]){
                    minHeap.push({edgeWeight, ngbr, node});
                }
            }
        }

        // check if all the nodes are processed or not
        for(int node = 1; node <= n; node++){
            if(!visited[node]){
                //cout << "node: " << node << endl;
                return -1;
            }
        }

        return 0;
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // considering type 3 edge as of highest priority , lowest edge weight = 0


        // first considering for alice
        // taking t3 edge wght as : 0, t1 : 1 and not using t2 type edge
        vvi aliceEdges;
        for(vi i : edges){
            int type = i[0], u = i[1], v = i[2];
            if(type == 2) continue;

            int edgeWeight = (type == 3 ? 0 : type);
            //cout << edgeWeight << " " << u << " " << v << endl;
            aliceEdges.push_back({edgeWeight, u, v});
        }

        int aliceAns = prims(n, aliceEdges);
        if(aliceAns == -1){
            //cout << "alice" << endl;
            return -1;
        }

        // next bob
        // considering wght as t3: 0, t2: 2, t1: not taking that
        vvi bobEdges;
        for(vi i : edges){
            int type = i[0], u = i[1], v = i[2];
            if(type == 1) continue;

            int edgeWeight = (type == 3 ? 0 : type);
            bobEdges.push_back({edgeWeight, u, v});
        }

        int bobAns = prims(n, bobEdges);
        if(bobAns == -1){
            //cout << "bob" << endl;
            return -1;
        }

        return edges.size() - uniqueEdges.size();

    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int n = 4;
    vvi edges = {{3,2,3},{1,1,2},{2,3,4}};
    cout << sol.maxNumEdgesToRemove(n, edges);

    return 0;
}