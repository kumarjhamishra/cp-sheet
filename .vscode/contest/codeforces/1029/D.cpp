#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void solve()
{
    /*
        let x operations of 1st type and y operations of 2nd type

        so a1 = 1.x + n.y
        and a2 = 2.x + (n-1).y

        x = y + a2 - a1
        substitute this in eqn 1
        y = (2a1 - a2)/(n+1)
        similarly get x and verify these x and y for rest of the elements
    */

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    double y = (double)(2*a[0] - a[1])/(n+1), x = y + a[1] - a[0];
    //cout << "y: " << y << endl;
    if((2*a[0] - a[1]) % (n+1) != 0 || x < 0 || y < 0){
        cout << "NO" << endl;
        return ;
    }
    
    for(int i = 1; i < n; i++){
        if((i+1) * x + (n-i) * y != a[i]){
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
    return ;
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