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
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // using Kahn's algorithm for BFS cycle detection 
        vi indegree(numCourses, 0);
        vvi adj(numCourses);

        for(auto i : prerequisites){
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        int processedNodes = 0;
        for(int node = 0; node < numCourses; node++){
            if(indegree[node] == 0) q.push(node);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            processedNodes++;

            for(int ngbr : adj[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0) q.push(ngbr);
            }
        }

        return processedNodes == numCourses;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCourses = 5;
    vvi prerequisites = {{1,4}, {2,4},{3,1},{3,2}};
    Solution sol;
    cout << sol.canFinish(numCourses, prerequisites);

    return 0;
}
// @lc code=end

