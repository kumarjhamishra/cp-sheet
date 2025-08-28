#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    string s = "";
    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        s.push_back(ch);
    }

    for(int i = 1; i < n; i++){
        if(s[i] < s[i-1]){
            cout << "YES" << endl;
            cout << i << " " << i+1 << endl;
            return ;
        }
    }

    cout << "NO" << endl;
    return ;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}