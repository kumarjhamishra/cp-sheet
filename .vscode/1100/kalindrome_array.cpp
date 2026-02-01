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

bool isPalindrom(vi&a , int& n, int &x){
    int i = 0, j = n-1;
    while(i <= j){
        // skip all the occurences of x
        if(a[i] == x) i++;
        else if(a[j] == x) j--;
        else if(a[i] != a[j]) return false;
        else{
            i++, j--;
        }
    }
    return true;
}

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto &i : a){
        cin >> i;
    }

    int i = 0;
    for(; i < (n+1)/2; i++){
        if(a[i] != a[n-1-i]){
            break;
        }
    }

    if(i == (n+1)/2){
        cout << "YES" << endl;
        return ;
    }

    int x1 = a[i], x2 = a[n-1-i];
    if(isPalindrom(a, n, x1) || isPalindrom(a, n, x2)){
        cout << "YES" << endl;
        return ;
    }
    cout << "NO" << endl;
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