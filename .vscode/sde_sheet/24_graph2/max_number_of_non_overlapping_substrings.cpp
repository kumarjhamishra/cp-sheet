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

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Stack {
        int values[26];
        int top = 0;
        void push(int val) { values[top++] = val; }
        int pop() { return values[--top]; }
        bool isEmpty() { return top == 0; }
    };

    void dfs(int v, vector<vector<bool>>& graph, Stack& stack, vector<bool>& visited) {
        if (!visited[v]) {
            visited[v] = true;
            for (int i = 0; i < 26; i++) {
                if (graph[v][i] && !visited[i]) {
                    dfs(i, graph, stack, visited);
                }
            }
            stack.push(v);
        }
    }

    void dfs(int v, vector<vector<bool>>& graph, vector<int>& batches, int batch, vector<int>& degree) {
        if (batches[v] < 0) {
            batches[v] = batch;
            for (int i = 0; i < 26; i++) {
                if (graph[i][v]) {
                    dfs(i, graph, batches, batch, degree);
                }
            }
        } else {
            if (batches[v] != batch) {
                degree[batches[v]]++;
            }
        }
    }

public:
    vector<string> maxNumOfSubstrings(string S) {
        int n = S.length();
        vector<int> mins(26, INT_MAX), maxs(26, -1);
        vector<bool> exists(26, false);
        vector<vector<int>> prefixSum(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i];
            prefixSum[i + 1][S[i] - 'a']++;
            mins[S[i] - 'a'] = min(mins[S[i] - 'a'], i);
            maxs[S[i] - 'a'] = max(maxs[S[i] - 'a'], i);
            exists[S[i] - 'a'] = true;
        }

        vector<vector<bool>> graph(26, vector<bool>(26, false));
        for (int i = 0; i < 26; ++i) {
            if (exists[i]) {
                for (int j = 0; j < 26; ++j) {
                    if (prefixSum[maxs[i] + 1][j] - prefixSum[mins[i]][j] > 0) {
                        graph[i][j] = true;
                    }
                }
            }
        }

        Stack stack;
        vector<bool> visited(26, false);
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && !visited[i]) {
                dfs(i, graph, stack, visited);
            }
        }

        int batch = 0;
        vector<int> batches(26, -1), degree(26, 0);
        while (!stack.isEmpty()) {
            int v = stack.pop();
            if (batches[v] < 0) {
                dfs(v, graph, batches, batch, degree);
                batch++;
            }
        }

        vector<string> res;
        for (int i = batch - 1; i >= 0; --i) {
            if (degree[i] == 0) {
                int minIdx = INT_MAX, maxIdx = -1;
                for (int j = 0; j < 26; ++j) {
                    if (batches[j] == i) {
                        minIdx = min(minIdx, mins[j]);
                        maxIdx = max(maxIdx, maxs[j]);
                    }
                }
                res.push_back(S.substr(minIdx, maxIdx - minIdx + 1));
            }
        }

        return res;
    }
};
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

class Solution {
private: 
    void dfs(int node, vb& visited, vvb& graph, stack<int>& st){
        visited[node] = true;

        for(int ngbr = 0; ngbr < 26; ngbr++){
            // node->ngbr and ngbr is not visited
            if(!visited[ngbr] && graph[node][ngbr]){
                dfs(ngbr, visited, graph, st);
            }
        }

        // when the node finishes it's dfs calls, push it in stack
        st.push(node);
    }

    void reverseDfs(int node, vvb& transpose_graph, vi& batches, int batch, vi& degree){
        if(batches[node] < 0){
            // this node is first time visited
            batches[node] = batch;

            for(int ngbr = 0; ngbr < 26; ngbr++){
                if(transpose_graph[node][ngbr]){
                    reverseDfs(ngbr, transpose_graph, batches, batch, degree);
                }
            }
        }

        else{
            if(batches[node] != batch){
                // means this ndoe is already a part of another SCC
                // then current batch depends on batches[node]
                degree[batches[node]]++;
            }
        }
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        // using the kosaraju's algo t find the strongly connceted components
        // all the char's which are in same SCC will be in the same substring


        // we will need the first and last index of the char's occurence
        int n = s.size();
        vvi ranges(26, vi(2, -1));

        // prefix frequency to quickly check which char's exist in a range
        vvi prefix(n+1, vi(26, 0)); // 1 based indexing in prefix 
        vb exists(26, false);

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            prefix[i+1] = prefix[i];
            prefix[i+1][idx]++;
            if(ranges[idx][0] == -1) ranges[idx][0] = i;
            ranges[idx][1] = i;
            exists[idx] = true;
        }

        // for char i, checking all char j's that appear between it's first and last using prefix sum,
        // coz then i will depend on j
        vvb graph(26, vb(26, false));

        for(int i = 0; i < 26; i++){
            if(!exists[i]) continue;

            for(int j = 0; j < 26; j++){
                int start = ranges[i][0], end = ranges[i][1];
                if(prefix[end+1][j] - prefix[start+1][j] > 0){
                    graph[i][j] = true;
                }
            }
        }

        // performing kosaraju's algo
        stack<int> st;
        vb visited(26, false);
        for(int node = 0; node < 26; node++){
            if(exists[node] && !visited[node]){
                dfs(node, visited, graph, st);
            }
        }

        // transpose the graph -> means reverse the direction of edges
        vvb transpose_graph(26, vb(26, false));

        for(int node = 0; node < 26; node++){
            visited[node] = false;
            for(int ngbr = 0; ngbr < 26; ngbr++){
                if(graph[node][ngbr]) transpose_graph[ngbr][node] = true;
                
            }
        }

        // perform the dfs on nodes depending on their finishing time
        int batch = 0;
        vi batches(26, -1), degree(26, 0);
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(batches[node] < 0){
                // means node is not visited 
                reverseDfs(node, transpose_graph, batches, batch, degree);
                batch++;
            }
        }


        // final part to get all the substrings
        vs ans;
        for(int i = batch-1; i >= 0; i--){
            if(degree[i] == 0){
                // means it's a SCC component
                int start = INT_MAX, end = INT_MIN;
                for(int j = 0; j < 26; j++){
                    // to get all those characters which belonges to the same batch
                    if(batches[j] == i){
                        start = min(start, ranges[j][0]);
                        end = max(end, ranges[j][1]);
                    }
                }
                ans.push_back(s.substr(start, end-start+1));
            }
        }

        return ans;

    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "abbaccd";
    vs ans = sol.maxNumOfSubstrings(s);
    for(string s : ans){
        cout << s << " ";
    }
    return 0;
}