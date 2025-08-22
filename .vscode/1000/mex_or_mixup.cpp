#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAX_N = 3e5+1;
vi prefixXor(MAX_N);

void precomputeXor(){
    prefixXor[0]= 0;
    for(int i = 1; i < MAX_N; i++){
        prefixXor[i] = (i ^ prefixXor[i-1]);
    }
}

void solve(){
    int a, b;
    cin >> a >> b;

    int baseXor = prefixXor[a-1];

    if(baseXor == b){
        cout << a << endl;
    }
    else if((baseXor ^ b) != a){
        cout << a + 1 << endl;
    }
    else{
        cout << a + 2 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precomputeXor();
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}