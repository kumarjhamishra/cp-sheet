#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    ll A, B, a, b, minimumOperations, increments, operations;
    cin >> A >> B;

    minimumOperations = A + 3; // a random large value
    for(increments = (B < 2 ? 1:0); increments < minimumOperations; increments++){
        b = B + increments;
        a = A;
        operations = increments;
        while(a){
            a /= b;
            operations++;
        }
        if(operations < minimumOperations) minimumOperations = operations;
    }
    cout << minimumOperations << endl;
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