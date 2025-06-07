#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    
    int count1 = 0, count0 = 0;
    for(char c : s){
        if(c == '1') count1++;
        else count0++;
    }

    // let's check of how much length can be we make a valid t
    int lengthT = 0;
    for(char c : s){
        if(c == '1' && count0){
            lengthT++;
            count0--;
        }
        else if(c == '0' && count1){
            lengthT++;
            count1--;
        }
        else break;
    }

    cout << n - lengthT << endl;
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