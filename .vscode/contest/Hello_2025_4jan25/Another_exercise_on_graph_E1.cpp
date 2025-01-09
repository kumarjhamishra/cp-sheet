#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;

bool compare(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> weights;
    unordered_map<int, vector<pair<int, int>>> adjList;

    // read edges
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        weights.push_back(w);
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // sort weight in ascending order
    sort(weights.begin(), weights.end());

    // read queries
    vector<vector<vector<int>>> queries(n+1); //{b, k, index(query no)}
    vector<int> results(q+1, INT_MAX);
    for(int i = 1; i <= q; i++){
        int a, b, k;
        cin >> a >> b >> k;
        if(b < a) swap(a, b);

        queries[a].push_back({b, k, i});
    }

    // process each node as a starting point
    // iterating over all the nodes
    for(int start = 1; start <= n; start++){
        // iterating over all the weights
        for(int weight : weights){
            // we will check which weight we can have as our answers
            // and then store the minimum of them


            // 0-1 BFS algo to store the distances to every node from start node with taking weight as weight
            // means all the weights > weight will marked as 1 and rest as 0, and then the shortest distances will be computed
            vector<int> dist(n+1, INT_MAX);
            dist[start] = 0;

            deque<int> dq;
            dq.push_back(start);

            // perform a modified BFS
            while(!dq.empty()){
                int curr = dq.front();
                dq.pop_front();

                for(auto& edge : adjList[curr]){
                    int ngbr = edge.first;
                    int edgeWght = edge.second;
                    int extraCost = (edgeWght > weight) ? 1 : 0;

                    if(dist[curr] + extraCost < dist[ngbr]){
                        dist[ngbr] = dist[curr] + extraCost;
                        if(extraCost == 0){
                            dq.push_front(ngbr);
                        }
                        else{
                            dq.push_back(ngbr);
                        }
                    }
                }
            }

            // update query results
            for(auto& query : queries[start]){
                int target = query[0];
                int maxEdges = query[1];
                int queryIndex = query[2];

                // this will will be eligible only if the edges we have used < maxEdges
                if(dist[target] < maxEdges){
                    // then store the minimum weight of them
                    results[queryIndex] = min(results[queryIndex], weight);
                }
            }


        }
    }

    // output results
    for(int i = 1; i <= q; i++){
        cout << results[i] << " ";
    }

    cout << endl;

    /*
    //{node1, node2, wght}
    vector<vector<int>> edges(m, vector<int>(3));
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--; // for 0 based indexing
        edges[i] = {u, v, w};
    }

    // sort the edges by weight
    sort(edges.begin(), edges.end(), compare);

    // value stores the weight of edges for each step
    vector<int> value(m+1);

    // dis represents shortest path length between all pair of vertices
    vector<vector<vector<int>>> dis(m+1, vector<vector<int>>(n, vector<int>(n, INT_MAX)));

    // distance of any node to itself 
    for(int i = 0; i < n; i++){
        dis[0][i][i] = 0;
    }

    // assigns all path length to be 1 initially
    for(auto edge : edges){
        int u = edge[0], v = edge[1];
        dis[0][u][v] = dis[0][v][u] = 1;
    }

    // floyd warshall algorithm to compute the shortest path length between all pair of nodes
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dis[0][i][j] = min(dis[0][i][j], dis[0][i][k] + dis[0][k][j]);
            }
        }
    }

    int p = 1;
    for(auto edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dis[p][i][j] = min({dis[p-1][i][j], dis[p-1][i][u] + dis[p-1][v][j], dis[p-1][i][v] + dis[p-1][u][j]});
            }
        }

        value[p++] = w;
    }

    cout<<"printing high values:"<<endl;
    for(int i : value){
        cout<<i<<" ";
    }
    cout<<endl;

    /*
    for(int i = 0; i < q; i++){
        int u, v, k;
        cin>>u>>v>>k;
        u--, v--; // for 0 based indexing

        int low = 0, high = m;
        while(high - low > 1){
            int mid = low + (high - low)/2;

            if(dis[mid][u][v] < k){
                high = mid;
            }
            else low = mid;
        }

        cout<<"high: "<<high <<" value: "<<value[high]<<" ";
    }
    

    for (int i = 0; i < q; i++) {
        int v, u, k;
        cin >> v >> u >> k;
        v--, u--;
        int low = 0, high = m;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (dis[mid][v][u] < k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout <<"high: "<<high<<" value: "<< value[high] << " \n"[i == q - 1];
    }
    cout<<endl;
    */
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}