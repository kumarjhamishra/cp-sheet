#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

ll findSmallestPrimeFactor(ll n){
    ll limit = sqrt(n);
    for(ll i = 3; i <= limit; i += 2){
        if(n % i == 0) return i; 
    }

    // n is itself a prime
    return n;
}

void solve(){
    ll n;
    cin >> n;

    if(n % 2 == 0){
        cout << n/2 << " " << n/2 << endl;
    }
    else{
        // for odd n find the smallest prime factor divisor of it
        ll smallestPrimeFactor = findSmallestPrimeFactor(n);
        // if the n is iteself a prime
        if(smallestPrimeFactor == n){
            cout << 1 << " " << n-1 << endl;
        }
        else{
            /*
            p = smallest prime factor
            (a,b) = (n/p, n - n/p)
            */
           cout << n/smallestPrimeFactor << " " << n - n/smallestPrimeFactor << endl;
        }
    }
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