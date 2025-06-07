#include <bits/stdc++.h>
using namespace std;
//bad_boy.cpp

void solve(){
    // we can maximize the distance travelled only when the yoyo's are placed at the farthest corners
    int n, m, i, j;
    cin >> n >> m >> i >> j;

    // the four corners will be {1, 1}, {1, m}, {n, 1}, {n, m}

    int x1 = -1, y1 = -1, x2 = -1, y2 = -1, maxDist = INT_MIN;
    if(maxDist < abs(i-1) + abs(j-1)){
        maxDist = abs(i-1) + abs(j-1);
        x1 = 1, y1 = 1;
        x2 = n, y2 = m;
    }
    if(maxDist < abs(i-1) + abs(j-m)){
        maxDist = abs(i-1) + abs(j-m);
        x1 = 1, y1 = m;
        x2 = n, y2 = 1;
    }
    if(maxDist < abs(i-n) + abs(j-1)){
        maxDist = abs(i-n) + abs(j-1);
        x1 = n, y1 = 1;
        x2 = 1, y2 = m;
    }
    if(maxDist < abs(i-n) + abs(j-m)){
        maxDist = abs(i-n) + abs(j-m);
        x1 = n, y1 = m;
        x2 = 1, y2 = 1;
    }

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
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