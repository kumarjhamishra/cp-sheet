#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // make all the valid combinations for first element
    // for first i+1 = 1, n-i = n

    /*
    vector<pii> validPairs;
    for(int i = 0; n * i <= a[0]; i++){
        int y = i;
        int x = a[0] - n*i;
        validPairs.push_back({x, y});
    }

    if(validPairs.empty()){
        cout << "NO" << endl;
        return ;
    }

    for(int i = 1; i < n; i++){
        bool isValid = false;

        for(auto pair : validPairs){
            int x = pair.first, y = pair.second;
            if(x * (i+1) + y * (n-i) == a[i]){
                isValid = true;
                break;
            }
        }

        if(!isValid){
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
    return ;

    */

    // base case
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }

    if (n == 2)
    {
        vector<pii> validPairs;
        for (int i = 0; n * i <= a[0]; i++)
        {
            int y = i;
            int x = a[0] - n * i;
            validPairs.push_back({x, y});
        }

        for (auto pair : validPairs)
        {
            int x = pair.first, y = pair.second;
            if (x * (2 + 1) + y * (n - 1) == a[1])
            {
                cout << "YES" << endl;
                return;
            }
        }

        cout << "NO" << endl;
        return;
    }

    int diff = (a[1] - a[0]);

    for (int i = 2; i < n; i++)
    {
        if ((a[i] - a[i - 1]) != diff)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
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