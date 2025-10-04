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
    vi p(n), visited(n+1, 0);
    for(auto &i : p) cin >> i;

    for(int i : p){
        if(i == 0) continue;
        visited[i] = 1;
    }

    priority_queue<int> maxHeap;
    for(int i = 1; i <= n; i++){
        if(!visited[i]) maxHeap.push(i);
    }

    for(int i = 0; i < n; i++){
        if(p[i] == 0){
            p[i] = maxHeap.top();
            maxHeap.pop();
        }
    }

    vi new_p = p;
    sort(new_p.begin(), new_p.end());
    int s = -1, e = -1;
    for(int i = 0; i < n; i++){
        if(p[i] != new_p[i]){
            if(s == -1) s = i, e = i;
            else e  = i;
        }
    }

    if(s == -1){
        cout << 0 << endl;
        return ;
    }
    cout << e-s+1 << endl;
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