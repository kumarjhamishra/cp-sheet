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

// class Node{
// public:
//     int val, parent, marking;
//     // a node will be either marked 0 or 1
//     Node(int val, int parent, int marking){
//         this->val = val;
//         this->parent = parent;
//         this->marking = marking;
//     }
// };

class Solution {
private:
    int n;
    //vb visited;
    //vi parent, marking;
    vi marking;
    bool bfs(int node, vvi &graph){
        queue<int> q;
        //Node src(node, -1, 0); // all the source nodes will have parent as -1 and initial marking as 0
        
        q.push(node);
        //visited[node] = true;
        marking[node] = 0;

        while(!q.empty()){
            //Node curr = q.front();
            int curr = q.front();
            q.pop();
            //int nodeVal = curr.val, nodeParent = curr.parent, nodeMarking = curr.marking;

            for(int ngbr : graph[curr]){
                //if(ngbr == parent[curr]) continue;
                if(marking[ngbr] == -1){
                    //Node ngrbNode(ngbr, nodeVal, 1 - nodeMarking);
                    q.push(ngbr);
                    //visited[ngbr] = true;
                    marking[ngbr] = 1 - marking[curr];
                }

                // came here means ngbr node is visited, check it's marking
                if(marking[ngbr] == marking[curr]) return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // when there is no cycle or even length cycle - bipartite
        // odd length cycle - no bipartite

        n = graph.size();

        //visited.resize(n, false);
        //parent.resize(n);
        marking.resize(n, -1);
        for(int node = 0; node < n; node++){
            if(marking[node] == -1 && !bfs(node, graph)){
                return false;
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
// @lc code=end