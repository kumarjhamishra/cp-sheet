#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//make_it_visible.cpp

void solve(){
    string n;
    cin >> n;

    // to be divisible by 25 the ending digits should be "25" or "50" or "75" or "00"

    // so we need to check whether any of these subsequences is made to be possible and for 
    // whom the minimum deletion possible

    int minimumSteps = INT_MAX;
    vector<string> v = {"25", "50", "75", "00"};
    for(auto x : v){
        int i = n.size() - 1;
        int j = x.size() - 1;
        int steps = 0;
        while(i >= 0 && j >= 0){
            if(n[i] == x[j]){
                i--;
                j--;
            }else{
                i--;
                steps++;
            }
        }
        if(j == -1){
            minimumSteps = min(minimumSteps, steps);
        }
    }

    cout << minimumSteps << endl;
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