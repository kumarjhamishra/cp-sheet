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
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
private:
    vi marking;

    bool dfs(int node, vvi& graph){
        for(int ngbr : graph[node]){
            if(marking[ngbr] == -1){
                marking[ngbr] = 1 - marking[node];
                if(!dfs(ngbr, graph)) return false;
            }
            if(marking[ngbr] == marking[node]) return false;
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        marking.resize(n, -1);

        for(int node = 0; node < n; node++){
            if(marking[node] == -1){
                marking[node] = 0;
                if(!dfs(node, graph)) return false;
            }
        }

        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vvi graph = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << sol.isBipartite(graph);
        

    return 0;
}