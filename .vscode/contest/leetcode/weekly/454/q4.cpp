#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<long long> vll; 
typedef vector<vector<pair<int, ll>>> vvpill;
typedef vector<vector<ll>> vvll;
const int MAX = 18;

/*
in a tree there is alwaya a unique path between 2 nodes
1e5 can be easily shown in 17 bits
*/

class Solution
{
private:
    int n;
    vvpill adj; // for each node we will store it's ngbr and the wght b/w them
    vvi up; // the row will be tke 2^k th parent and the cols will be the node - [k][node] = 2^k parent of node
    vvll distup; // the row will be the 2^k the parent and the col will be node - [k][node] = distance b/w node and it's 2^k th parent
    vi depth; // the depth of node measure from root node

    void dfs(int node, int parent){
        // storing 1st parent of node
        up[0][node] = parent;

        for(auto &[child, wght] : adj[node]){
            // it's a bidirectional tree so ignore the node's parent as child
            if(child == parent) continue;
            // depth of child will be one more than it's parent
            depth[child] = depth[node] + 1;
            // distance b/w child and it's 1st parent (node) will be the edge weight
            distup[0][child] = wght;
            dfs(child, node);
        }
    }

    void build(){
        // 2^1 = 2nd, 2^2 = 4th , ... 2^k
        for(int k = 1; k < MAX; k++){
            // 4th parent of a node will be the 2nd parent of it's 2nd parent
            // also the distance to 4th parent will be sum of distance to 2nd parent and distance of 2nd parent to it's 2nd parent
            for(int node = 0; node < n; node++){
                up[k][node] = up[k-1][up[k-1][node]];
                distup[k][node] = distup[k-1][node] + distup[k-1][up[k-1][node]];
            }
        }
    }

    int lca(int u, int v){
        // first we need to make the level of u and v equal

        // assuming that level of u will always be <= level of v
        if(depth[u] > depth[v]) swap(u, v);

        // now make the level of v and u equal
        int diff = depth[v] - depth[u];

        if(diff){
            for(int k = 0; k < MAX; k++){
                if(diff & (1 << k)) v = up[k][v];
            }
        }

        // check if both becomes equal
        if(u == v) return u;

        // now we will make the u and v jump up till when they both have unequal parent - which is just below the lca
        // bcoz at and after lca they both will have surely have same parent
        // so first we will try to make large jumps and it will be invalid the reduce the jump by half
        // like 8th parent , 4th parent (not valid) ok so 2nd parent then 1st parent
        for(int k = MAX-1; k >= 0; k--){
            int uParent = up[k][u], vParent = up[k][v];

            if(uParent != vParent){
                u = uParent;
                v = vParent;
            }
        }

        // now the u and v are just 1 level below their lca
        return up[0][u];
    }

    ll calculateDistance(int node, int parent){
        ll totalDistance = 0;

        int diff = depth[node] - depth[parent];
        
        // if the level diff is 5(101) then it can be cover as 1st parent then 4th parent of 1st parent
        // and distance also likewise
        for(int k = 0; k < MAX; k++){
            if(diff & (1 << k)){
                totalDistance += distup[k][node];
                node = up[k][node];
            }
        }

        return totalDistance;
    }
public:
    vector<int> findMedian(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        this->n = n;
        adj.resize(n);
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        up.resize(MAX, vi(n));
        distup.resize(MAX, vll(n));
        depth.resize(n, 0);

        // starting with root node as 0 and parent as 0 as root node is himself parent
        dfs(0, 0);

        // now perform the binary lifting and build the table
        build();

        
        vi ans;
        for(auto q : queries){
            int u = q[0], v = q[1];
            // the path b/w u and v will surely travel through their lca
            int l = lca(u, v);
            // get the distance from lca to u and lca to v;
            ll du = calculateDistance(u, l), dv = calculateDistance(v, l);
            ll half = (du + dv + 1) / 2;

            if(u == v){
                ans.push_back(u);
                continue;
            }

            // either this >= half distance will be between u and lca or in b/w v and lca
            int node = u;
            ll rem = half;
            // means the ans node is b/w lca and v
            if(du < half) node = v;

            // now we will jump up the node till the distance b/w that parent node and node will be less than half
            // and then the ans node will be the the 1st parent of that node bcoz their the distance will either become equal or > than half
            for(int k = MAX-1; k >= 0; k--){
                if(distup[k][node] < rem){
                    rem -= distup[k][node];
                    node = up[k][node];
                }
            }

            if(du < half && calculateDistance(up[0][node], l) + du < half){
                ans.push_back(node);
                continue;
            }

            ans.push_back(up[0][node]);
        }
        return ans;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

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