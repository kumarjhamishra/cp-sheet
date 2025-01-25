#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

class UnionFind{
private:
    vector<int> par;
    vector<int> sz;

public:
    UnionFind(int n){
        // parent array should be of size n
        par = vector<int>(n);
        // in starting every element is his parent
        iota(par.begin(), par.end(), 0); // iota will assign value like 0, 1, 2, 3, 4, ...
        // size of each component
        sz = vector<int>(n, 1);
    }

    // function to find parent of a node
    int find(int u){
        if(par[u] != par[par[u]]){
            par[u] = find(par[par[u]]);
        }

        return par[u];
    }

    // function to check if both nodes are in same component
    bool connected(int u, int v){
        u = find(u);
        v = find(v);

        return u == v;
    }

    // function to join 2 nodes in same component
    void join(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return ;

        // if size of v is greater then make v as parent of u
        if(sz[u] <= sz[v]){
            sz[v] += sz[u];
            par[u] = v;
        }
        else{
            sz[u] += sz[v];
            par[v] = u;
        }

        return ;
    }
};

void solve(){
    ll n;
    cin >> n;

    // make the union find for graph F and G
    UnionFind uf1(n), uf2(n);

    ll m1, m2;
    cin >> m1 >> m2;

    vector<p> edges1(m1), edges2(m2);

    // making the graph 0 indexed
    for(ll i = 0; i < m1; i++){
        ll a, b;
        cin >> a >> b;
        edges1[i] = {a-1, b-1};
    }

    for(ll i = 0; i < m2; i++){
        ll a, b;
        cin >> a >> b;
        edges2[i] = {a-1, b-1};
    }

    // run dsu for graph G
    for(auto& [a, b] : edges2){
        uf2.join(a, b);
    }

    ll operations = 0;
    for(auto& [a, b] : edges1){
        // if the graph G has edge b/w a and b
        // then join that edge in F also
        if(uf2.connected(a, b)){
            uf1.join(a, b);
        }
        else{
            // this edge is not present in graph G so remove it
            operations++;
        }
    }

    // now we need to find the no of components in graph F and G
    set<ll> s1, s2;
    for(ll i = 0; i < n; i++){
        s1.insert(uf1.find(i));
        s2.insert(uf2.find(i));
    }

    //the no of edges we need to add is no of components in F - no of components in G
    operations += s1.size() - s2.size();
    cout << operations << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}