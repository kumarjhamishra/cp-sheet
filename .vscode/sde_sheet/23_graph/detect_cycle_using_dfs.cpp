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
    int processedNodes;
    vi indegree;
    vvi adj;

    void dfs(int node){
        cout << "node: " << node << endl;
        processedNodes++;

        for(int ngbr : adj[node]){
            indegree[ngbr]--;
            if(indegree[ngbr] == 0){
                dfs(ngbr);
            }
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // using Kahn's algorithm for DFS cycle detection 
        indegree.resize(numCourses, 0);
        adj.resize(numCourses);

        for(auto i : prerequisites){
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        processedNodes = 0;
        for(int node = 0; node < numCourses; node++){
            if(indegree[node] == 0) dfs(node);
        }
        cout << "processedNodes: " << processedNodes << endl;
        return processedNodes == numCourses;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCourses = 2;
    vvi prerequisites = {{0,1}};
    Solution sol;
    cout << sol.canFinish(numCourses, prerequisites);

    return 0;
}
// @lc code=end

