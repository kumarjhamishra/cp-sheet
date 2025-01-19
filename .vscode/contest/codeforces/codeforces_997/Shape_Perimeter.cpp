#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<p> xy;
    for(int i = 1; i <= n; i++){
        int xi, yi;
        cin >> xi >> yi;
        xy.push_back({xi, yi});
    }

    int totalPerimeter = n * 4 * m;

    
    p preOrigin = {xy[0].first, xy[0].second};
    p preTopRight = {xy[0].first + m, xy[0].second + m};
    for(int i = 1; i < n; i++){
        p currStart = {preOrigin.first + xy[i].first , preOrigin.second + xy[i].second};

        int l = preTopRight.first - currStart.first;
        int b = preTopRight.second - currStart.second;

        totalPerimeter -= 2 * (l + b);
        preOrigin = currStart;
        preTopRight = {preOrigin.first + m, preOrigin.second + m};
    }

    cout << totalPerimeter << endl;
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