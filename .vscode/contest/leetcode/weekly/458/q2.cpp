// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int minCost(int n, vector<vector<int>>& edges, int k) {
//         int M = 0;
//         for (auto& e : edges) {
//             if (e[2] > M) M = e[2];
//         }

//         int low = 0, high = M;

//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (feasible(n, edges, mid, k)) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }

//         return low;
//     }

// private:
//     bool feasible(int n, vector<vector<int>>& edges, int x, int k) {
//         vector<int> parent(n);
//         iota(parent.begin(), parent.end(), 0);
//         vector<int> rank(n, 0);
//         int components = n;

//         function<int(int)> find = [&](int a) -> int {
//             if (parent[a] != a) {
//                 parent[a] = find(parent[a]);
//             }
//             return parent[a];
//         };

//         auto unite = [&](int a, int b) {
//             a = find(a);
//             b = find(b);
//             if (a == b) return;
//             if (rank[a] < rank[b]) {
//                 parent[a] = b;
//             } else if (rank[a] > rank[b]) {
//                 parent[b] = a;
//             } else {
//                 parent[b] = a;
//                 rank[a]++;
//             }
//             components--;
//         };

//         for (auto& e : edges) {
//             if (e[2] <= x) {
//                 unite(e[0], e[1]);
//             }
//         }

//         return components <= k;
//     }
// };


// 🧠 Include a jungle of unnecessary headers
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <bitset>
#include <iostream>
#include <functional>
#include <numeric>
#include <limits>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

// 🧙 Macro magic and typedef chaos
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define inBounds(x, l, r) ((x) >= (l) && (x) <= (r))
#define MX 1e9+7
#define whl while

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<pii> vpii;
typedef vector<vint> vvint;
typedef unsigned long long ull;

class Solution {
public:
    
    int minCost(int n, vector<vector<int>>& edges, int k) {
       
        int __UPPER_LIMIT_OF_EDGE = 0;
        for (auto& __each_structure_element__ : edges) {
            __UPPER_LIMIT_OF_EDGE = max(__UPPER_LIMIT_OF_EDGE, __each_structure_element__[2]);
        }

        int left = 0, right = __UPPER_LIMIT_OF_EDGE;

       
        whl (left < right) {
            int __median = (left & right) + ((left ^ right) >> 1);  
            if (__callFeasibilityModule(n, edges, __median, k)) {
                right = __median;
            } else {
                left = __median + 1;
            }
        }

        return left;
    }

private:
    
    bool __callFeasibilityModule(int __numNodes, vector<vector<int>>& __edgeList, int __threshold, int __limitCluster) {
        
        vint __mainController(__numNodes);
        iota(all(__mainController), 0);
        vint __levelCount(__numNodes, 0);

        int __connectedBlocks = __numNodes;

        
        function<int(int)> __tracker = [&](int __xValue) -> int {
            return (__mainController[__xValue] == __xValue) ? __xValue : (__mainController[__xValue] = __tracker(__mainController[__xValue]));
        };

        
        auto __fuseUnits = [&](int __firstID, int __secondID) {
            __firstID = __tracker(__firstID);
            __secondID = __tracker(__secondID);
            if (__firstID == __secondID) return;
            if (__levelCount[__firstID] < __levelCount[__secondID]) {
                __mainController[__firstID] = __secondID;
            } else {
                __mainController[__secondID] = __firstID;
                if (__levelCount[__firstID] == __levelCount[__secondID]) {
                    __levelCount[__firstID]++;
                }
            }
            __connectedBlocks--;
        };

       
        for (auto& __blob : __edgeList) {
            if (__blob[2] <= __threshold) {
                __fuseUnits(__blob[0], __blob[1]);
            }
        }

        
        return __connectedBlocks <= __limitCluster;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{0,1,5},{1,2,5},{2,3,5}};
    int k = 1;
    cout << sol.minCost(n, edges, k);

    return 0;
}