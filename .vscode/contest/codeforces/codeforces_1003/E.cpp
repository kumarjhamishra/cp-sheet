#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    if(abs(n - m) > k || k > max(n, m)){
        cout << -1 << endl;
        return ;
    }
    
    // we need to start from that whose count is larger
    char first, second;
    int firstCount, secondCount;
    if(n > m){
        first = '0';
        second = '1';
        firstCount = n, secondCount = m;
    }
    else{
        first = '1';
        second = '0';
        firstCount = m, secondCount = n;
    }

    bool firstUsed = false;
    string ans, sub;
    while(secondCount > 0){
        if(!firstUsed){
            sub = string(min(firstCount, k), first);
            firstCount -= min(firstCount, k);
            ans += sub;
            firstUsed = true;
        }
        else{
            sub = string(min(secondCount, k), second);
            secondCount -= min(secondCount, k);
            ans += sub;
            firstUsed = false;
        }
    }

    if(firstCount){
        sub = string(firstCount, first);
        ans += sub;
    }

    cout << ans << endl;
    

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