#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define pb push_back

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int toProtect = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '1'){
            if(i == 0) toProtect++;
            else{
                // to find a one
                bool found = false;
                for(int j = i-1; j >= max(0, (i-1-k+2)); j--){
                    if(s[j] == '1'){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    toProtect++;
                }
            }
        }
    }
    cout << toProtect << endl;
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