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

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> mp;

        int n = 0;
        for(auto i : equations){
            string u = i[0], v = i[1];
            if(mp.find(u) == mp.end()) mp[u] = n++;
            if(mp.find(v) == mp.end()) mp[v] = n++;
        }

        //cout << n << endl;

        vector<vector<double>> cost(n, vector<double>(n, -1.00000));
        
        vvi isProcessed(n, vi(n, 0)); // 0 - unprocessed, 1 - processed , 2 - locked
        for(int i = 0; i < equations.size(); i++){
            int u = mp[equations[i][0]], v = mp[equations[i][1]];
            cost[u][v] = values[i];
            isProcessed[u][v] = 1;

            cost[v][u] = (1.00000/values[i]);
            isProcessed[v][u] = 1;
        }

        for(int u = 0; u < n; u++){
            cost[u][u] = 1.00000;
            isProcessed[u][u] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << cost[i][j] << " ";
            }
            cout << endl;
        }

        for(int node = 0; node < n; node++){
            for(int u = 0; u < n; u++){
                for(int v = 0; v < n; v++){
                    if(node != u && node != v && u != v && isProcessed[u][v] != 2 && cost[u][node] != -1.00000 && cost[node][v] != -1.00000){
                        if(isProcessed[u][v] == 0){
                            
                            cost[u][v] = cost[u][node] * cost[node][v];
                            isProcessed[u][v] = 1; // processed
                            
                        }
                        else if(fabs(cost[u][v] - (cost[u][node] * cost[node][v])) > 1e-8){
                            cout << "hello" << endl;
                            cout << "org: " << cost[u][v] << endl;
                            cout << "new: " << cost[u][node] * cost[node][v] << endl;
                            // already processed
                            cost[u][v] = -1.00000;
                            isProcessed[u][v] = 2; // locking , now don't process u->v

                            cout << "u: " << u << " v: " << v << " node: " << node << endl;
                        }
                    }
                }
            }
        }

        cout << "hello" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << cost[i][j] << " ";
            }
            cout << endl;
        }

        vector<double> ans;
        for(auto q : queries){
            string us = q[0], vs = q[1];
            if(mp.find(us) == mp.end() || mp.find(vs) == mp.end()){
                ans.push_back(-1.00000);
                //continue;
            }
            else{
                int u = mp[us], v = mp[vs];
                ans.push_back(cost[u][v]);
                // if(cost[u][v] != -1.00000) ans.push_back(cost[u][v]);
                // else if(cost[v][u] != -1.00000) ans.push_back((1.00000/cost[v][u]));
                // else ans.push_back(-1.00000);
            }
        }

        return ans;

    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vs> equations = {{"a","b"},{"b","c"}};
    vd values = {2.0, 3.0};
    vector<vs> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    Solution sol;
    vd ans = sol.calcEquation(equations, values, queries);
    for(double d : ans){
        cout << d << endl;
    }

    return 0;
}