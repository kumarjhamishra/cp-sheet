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
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef tuple<int, int, int> tiii;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        // make the adjency list
        vector<vector<pii>> adj(n);
        for(auto i : edges){
            int u = i[0], v = i[1], time = i[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // {fees, time, node}
        priority_queue<tiii, vector<tiii>, greater<>> minHeap;

        // src is 0 and destination is n-1
        vi time(n, INT_MAX), fees(n, INT_MAX);

        minHeap.push({passingFees[0], 0, 0});
        time[0] = 0, fees[0] = passingFees[0];

        while (!minHeap.empty())
        {
            auto [currFee, currTime, currNode] = minHeap.top();
            minHeap.pop();

            if(currNode == n-1 && currTime <= maxTime) return currFee;
            
            for(pii ngbr : adj[currNode]){
                int ngbrNode = ngbr.first, wght = ngbr.second;
                if(currTime + wght <= maxTime && currTime + wght < time[ngbrNode]){
                    time[ngbrNode] = currTime + wght;
                    // the heap will ensure that we process the cheapest fee first among all the valid options
                    minHeap.push({currFee + passingFees[ngbrNode], time[ngbrNode], ngbrNode});
                }
            }
        }

        return -1;
        
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}