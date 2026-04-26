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
    int n;
    cin >> n;
    vi a(n);
    for(auto &i : a) cin >> i;

    if(n <= 2){
        cout << -1 << endl;
        return ;
    }

    int mini = 1, maxi = n, i = 0, j = n-1;
    /*
    while(i < j){
        if(a[i] != mini && a[i] != maxi && a[j] != mini && a[j] != maxi){
            cout << i + 1 << " " << j + 1 << endl;
            return ;
        }
        if(a[i] == mini || a[i] == maxi){
            if(a[i] == mini){
                mini += 1;
            }
            else{
                maxi -= 1;
            }
            i++;
        }
        if(a[j] == mini || a[j] == maxi){
            if(a[j] == mini){
                mini += 1;
            }
            else{
                maxi -= 1;
            }
            j--;
        }
    }
    cout << -1 << endl;
    return ;
    */

    while(i <= j){
        if(a[i] == mini){
            mini++;
            i++;
        }
        else if(a[i] == maxi){
            maxi--;
            i++;
        }
        else if(a[j] == mini){
            mini++;
            j--;
        }
        else if(a[j] == maxi){
            maxi--;
            j--;
        }
        else{
            break;
        }
    }
    if(i <= j){
        cout << i+1 << " " << j+1 << endl;
    }
    else{
        cout << -1 << endl;
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