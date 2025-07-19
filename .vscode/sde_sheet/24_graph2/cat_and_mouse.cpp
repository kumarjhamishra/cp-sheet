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

/*
undirected graph
mouse starts at node 1 and first starts, cat starts at 2, hole at node 0
cat not allowed to go to hole (node 0)

game ends:
1) cat occupies mouse -> return 2
2) mouse reaches hole -> return 1
3) position repeated -> draw -> return 0
*/

class Solution {
private:
    vector<tiii> getParents(int m, int c, int t, vvi& graph){
        /*
        If current turn was mouse’s, the previous turn was cat’s, and cat must have been at one of its neighbors (excluding node 0).
        If current turn was cat’s, the previous turn was mouse’s, and mouse must have been at one of its neighbors.
        */

        vector<tiii> parents;
        if(t == 0){
            // moust just moved to 'm', means it was cat's turn last
            // all the prev posn's where cat could've been
            for(int pre : graph[c]){
                // cat can't go to node 0
                if(pre == 0) continue;
                parents.push_back({m, pre, 1});
            }
        }
        else{
            // Cat just moved to 'c', so it was Mouse’s turn last.
            // We look at all positions where Mouse could’ve been.
            for(int pre : graph[m]){
                parents.push_back({pre, c, 0});
            }
        }

        return parents;
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        // mouse at i, cat at j, turn -> 0 = mouse, 1 = cat
        // color[i][j][t] = 0(draw), 1(mouse), 2(cat)
        vector<vvi> color(n, vvi(n, vi(2, 0)));
        vector<vvi> degree(n, vvi(n, vi(2, 0)));

        // precompute degree: number of moves from each state
        for(int m = 0; m < n; m++){
            for(int c = 0; c < n; c++){
                // when it's the mouse turn, it can move to any of it's adjacent nodes
                degree[m][c][0] = graph[m].size();

                // initialising cat moves with 0 and then taking only those where the next move for cat is not 0
                // coz cat is not allowed to go on position 0
                for(int nxt : graph[c]){
                    if(nxt != 0) degree[m][c][1]++;
                }
            }
        }

        // initialize terminal states
        queue<tiii> q;

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= 1; t++){
                // mouse will whenever it reaches hole, doesn't matter where cat is, and who's turn
                color[0][i][t] = 1;
                q.push({0, i, t});

                // cat will win when it's catches mouse
                color[i][i][t] = 2;
                q.push({i, i, t});
            }
        }

        while(!q.empty()){
            auto [m,c,t] = q.front();
            q.pop();
            
            int result = color[m][c][t];

            // backward propagation
            for(auto [pm, pc, pt] : getParents(m, c, t, graph)){
                if(color[pm][pc][pt] != 0) continue; // aready computed

                if((result == 1 && pt == 0) || (result == 2 && pt == 1)){
                    // player whose turn it is can force a win
                    color[pm][pc][pt] = result;
                    q.push({pm, pc, pt});
                }

                else{
                    // this leads to a losing option, decreas options
                    degree[pm][pc][pt]--;
                    if(degree[pm][pc][pt] == 0){
                        // no moves left - forces loss
                        color[pm][pc][pt] = result;
                        q.push({pm, pc, pt});
                    }
                }
            }
        }

        return color[1][2][0]; // mouse at 1, cat at 2, mouse's turn
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}