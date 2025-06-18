#include <bits/stdc++.h> 
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <functional>

using namespace std;


#define loop(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define pii pair<int, int>
#define int long long

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<vector<int>> Matrix;
//typedef pair<int, int> pii;

class Solution {
private:
    int N, LG;
    vector<vector<pii>> tunnel;
    vector<vi> ancesTable;
    vector<int> lvl, distFromZero, immParent;

    void synthesizeGraph(Matrix& wires) {
        tunnel.resize(N);
        for (auto& conn : wires) {
            int from = conn[0], to = conn[1], cost = conn[2];
            tunnel[from].pb(mp(to, cost));
            tunnel[to].pb(mp(from, cost));
        }
    }

    void runBFS(int root) {
        lvl.assign(N, -1);
        distFromZero.assign(N, 0);
        immParent.assign(N, -1);
        queue<int> pendulum;
        pendulum.push(root);
        lvl[root] = 0;

        while (!pendulum.empty()) {
            int curr = pendulum.front(); pendulum.pop();
            for (auto& edge : tunnel[curr]) {
                int adj = edge.F, weight = edge.S;
                if (lvl[adj] == -1) {
                    lvl[adj] = lvl[curr] + 1;
                    distFromZero[adj] = distFromZero[curr] + weight;
                    immParent[adj] = curr;
                    pendulum.push(adj);
                }
            }
        }
    }

    void computeBinaryLifting() {
        LG = 0;
        while ((1 << LG) <= N) ++LG;
        ancesTable.assign(LG, vi(N, -1));

        loop(i, 0, N) ancesTable[0][i] = immParent[i];

        loop(j, 1, LG) {
            loop(i, 0, N) {
                int prev = ancesTable[j - 1][i];
                ancesTable[j][i] = (prev == -1 ? -1 : ancesTable[j - 1][prev]);
            }
        }
    }

    function<int(int, int)> ancestorFinder = [&](int node, int jump) {
        loop(i, 0, LG) {
            if ((jump >> i) & 1) {
                if (node == -1) break;
                node = ancesTable[i][node];
            }
        }
        return node;
    };

    function<int(int, int)> lowestCommonAncestor = [&](int a, int b) {
        if (lvl[a] < lvl[b]) swap(a, b);
        int diff = lvl[a] - lvl[b];
        a = ancestorFinder(a, diff);
        if (a == b) return a;
        for (int i = LG - 1; i >= 0; --i) {
            if (ancesTable[i][a] != ancesTable[i][b]) {
                a = ancesTable[i][a];
                b = ancesTable[i][b];
            }
        }
        return ancesTable[0][a];
    };

public:
    vector<int> findMedian(int nodes, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        N = nodes;
        synthesizeGraph(edges);
        runBFS(0);
        computeBinaryLifting();

        vector<int> results;
        for (auto& interrogate : queries) {
            int source = interrogate[0], destination = interrogate[1];
            int ancestor = lowestCommonAncestor(source, destination);

            LL fullPath = distFromZero[source] + distFromZero[destination] - 2 * distFromZero[ancestor];
            LL pathToU = distFromZero[source] - distFromZero[ancestor];

            if (2 * pathToU >= fullPath) {
                int lo = lvl[ancestor], hi = lvl[source], res = source;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    int midNode = ancestorFinder(source, lvl[source] - mid);
                    if (midNode == -1) {
                        hi = mid - 1;
                        continue;
                    }
                    if (2 * (distFromZero[source] - distFromZero[midNode]) >= fullPath) {
                        res = midNode;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                results.pb(res);
            } else {
                LL remain = fullPath - 2 * pathToU;
                int lo = lvl[ancestor], hi = lvl[destination], res = destination;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    int midNode = ancestorFinder(destination, lvl[destination] - mid);
                    if (midNode == -1) {
                        hi = mid - 1;
                        continue;
                    }
                    if (2 * (distFromZero[midNode] - distFromZero[ancestor]) >= remain) {
                        res = midNode;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                results.pb(res);
            }
        }

        return results;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}