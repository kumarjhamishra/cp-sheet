#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool compare(const pii& a, const pii& b){
    if(a.first != b.first) return a.first > b.first;

    return a.second < b.second;
}

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<pii> health(n);
    for(int i = 0; i < n; i++){
        // calculate the left over health
        int h;
        cin >> h;
        h %= k;
        if(h == 0) h = k;

        health[i] = {h, i+1};
    }

    sort(health.begin(), health.end(), compare);

    for(int i = 0; i < n; i++){
        cout << health[i].second << " ";
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