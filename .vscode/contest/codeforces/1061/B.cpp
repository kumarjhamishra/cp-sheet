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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vi a(q);
    for(auto &i : a) cin >> i;

    // check if even a single 'B' type machine is present or not
    bool isPresentB = false;
    for(char ch : s){
        if(ch == 'B'){
            isPresentB = true;
            break;
        }
    }

    if(!isPresentB){
        // no B present
        for(int a_i : a){
            cout << a_i << endl;
        }
        //cout << endl;
    }
    else{
        for(int a_i : a){
            int sec = 0, a_c = a_i, i = 0;
            while(a_c){
                if(s[i] == 'A'){
                    a_c -= 1;
                }
                else{
                    a_c /= 2;
                }
                sec++;
                i = (i + 1) % n;
            }
            cout << sec << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}