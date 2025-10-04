#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

void solve(){
    int n;
    cin >> n;

    vvi list;
    for(int i = 0; i < n-1; i++){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        list.push_back({u, v, x, y});
    }

    /*
    1. make the directed graph: smaller value for node -> larger value for node
    2. maintain the indegree for each node 1 to n
    3. do the bfs and in one go process all the nodes which has indegree 0
    4. then decreasing their connected nodes and pushing those who indegree becomes 0
    5. maintain a variable whose value will start from 1 and by using that value for the node increment the value of variable
    */

    // make the adjency list and indegree list
    vvi adj(n+1);
    vi indeg(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int u = list[i][0], v = list[i][1], x = list[i][2], y = list[i][3];
        if(x > y){
            adj[v].push_back(u);
            indeg[u]++;
        }
        else{
            adj[u].push_back(v);
            indeg[v]++;
        }
    }

    int val = 1;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }

    vi ans(n+1);
    while(!q.empty()){
        //int currSize = q.size();
        int node = q.front();
        q.pop();

        ans[node] = val++;
        // now decrement the indegree value of each of it's ngbr
        for(int ngbr : adj[node]){
            indeg[ngbr]--;
            if(indeg[ngbr] == 0) q.push(ngbr);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}