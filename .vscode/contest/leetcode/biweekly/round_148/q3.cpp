#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
class Solution {
private:
    vector<vector<p>> adjList;
    // in path we will store all those weights which are encountering during the dfs calls to determine the path and the pathSum
    vector<int> traceColor, path, nums;
    int maxLength = 0, minNodes = INT_MAX;

    void dfs(int node, int parent, int pathSum, int start, int end){
        // find the previous index where this color was earlier present
        int prevDepth = traceColor[nums[node]];

        // if the current path contains already this color, then shorten the path from the left side(start side)
        while(start <= prevDepth){
            pathSum -= path[start++];
        }

        if(pathSum >= maxLength){
            if(pathSum > maxLength){
                maxLength = pathSum;
                minNodes = end - start + 1;
            }
            else{
                minNodes = min(minNodes, end - start + 1);
            }
        }

        // now for the aage vali calls mark this index/node where this particular value/color was found
        traceColor[nums[node]] = end;

        for(auto& [ngbr, wght] : adjList[node]){
            if(ngbr != parent){
                path.push_back(wght);
                dfs(ngbr, node, pathSum+wght, start, end+1);
                
                // for backtracking after the call finishes remove this weight from the path
                path.pop_back();
            }
        }

        // also for backtracking of again set the index of for the same color to that index which we have used
        traceColor[nums[node]] = prevDepth;
    }
    
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        
        int n = nums.size();
        this->nums = nums;
        // make the adjency list: u -> {v, wght}
        adjList.resize(n);
        for(auto& edge : edges){
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        // now during the dfs calls we also want to get that at which previous index or node did we find this current color
        traceColor.resize(50000+1, -1);
        dfs(0, -1, 0, 0, 0); // node, parent, pathSum, start, end
        // start and end helps in determining the length of special paths
        return {maxLength, minNodes};
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        //solve();
    }

    return 0;
}