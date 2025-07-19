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
typedef vector<vector<pii>> vvpii;
typedef vector<vvpii> vvvpii;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vvpii adj(n);

        for(auto i : flights){
            int u = i[0], v = i[1], price = i[2];
            adj[u].push_back({v, price}); // directed edge
        }

        // priority_queue<tiii, vector<tiii>, greater<>> minHeap;
        // vi prices(n, INT_MAX);

        // prices[src] = 0;
        // minHeap.push({0, -1, src}); // {cost, stops in b/w city and src, city}

        // while(!minHeap.empty()){
        //     auto [price, stops, city] = minHeap.top();
        //     minHeap.pop();

        //     if(city == dst) return price;
        //     if(stops == k) continue; // now processing this city will make the stops for next city k+1 which is invalid

        //     for(pii ngbr : adj[city]){
        //         int ngbrCity = ngbr.first, cost = ngbr.second;

        //         if(prices[city] + cost < prices[ngbrCity]){
        //             prices[ngbrCity] = prices[city] + cost;
        //             minHeap.push({prices[ngbrCity], stops+1, ngbrCity});
        //         }
        //     }
        // }

        // return -1;



        vvi prices(n, vi(k+1, 1e9));
        
        // base cases
        for(int stops = 0; stops <= k; stops++) prices[src][stops] = 0;

        for(auto i : flights){
            int u = i[0], v = i[1], cost = i[2];
            if(u != src) continue;

            prices[v][0] = cost;
        }

        for(int stops = 1; stops <= k; stops++){
            for(auto i : flights){
                int u = i[0], v = i[1], cost = i[2];
                if(prices[u][stops-1] + cost < prices[v][stops]){
                    prices[v][stops] = prices[u][stops-1] + cost;
                }
            }
        }

        // int lowestPrice = 1e9;
        // for(int stops = 0; stops <= k; stops++) lowestPrice = min(lowestPrice, prices[dst][stops]);

        // return lowestPrice < 1e9 ? lowestPrice : -1;
        return prices[dst][k] != 1e9 ? prices[dst][k] : -1;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}