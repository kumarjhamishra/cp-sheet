#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;

struct hash_pair {
    size_t operator()(const pii &p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

vector<pii> knight_moves(int a, int b){
    return {{a, b}, {a, -b}, {-a, b}, {-a, -b}, 
    {b, a}, {b, -a}, {-b, a}, {-b, -a}};
}

void solve(){
    int a, b, xk, yk, xq, yq;
    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;

    vector<pii> moves = knight_moves(a, b);
    unordered_set<pii, hash_pair> st;

    for(auto i : moves){
        int x = xk + i.first;
        int y = yk + i.second;
        st.insert({x, y});
    }

    int cnt = 0;
    for(auto i: moves){
        int x = xq + i.first;
        int y = yq + i.second;

        if(st.count({x, y})) cnt++;
    }

    cout << cnt << endl;
    return ;
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