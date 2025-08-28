#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

bool isFair(ll n){
    ll temp_n = n;
    while(temp_n){
        ll digit = temp_n % 10;
        if(digit != 0 && n % digit) return false;
        temp_n /= 10;
    }

    return true;
}

void solve(){
    ll n;
    cin >> n;

    while(true){
        if(isFair(n)){
            break;
        }
        n++;
    }
    cout << n << endl;
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