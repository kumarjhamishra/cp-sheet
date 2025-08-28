#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int minimumMoves = 0, balance = 0;
    for(char ch : s){
        if(ch == '(') balance++;
        else{
            balance--;
            if(balance < 0){
                balance = 0;
                minimumMoves++;
            }
        }
    }

    cout << minimumMoves << endl;
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