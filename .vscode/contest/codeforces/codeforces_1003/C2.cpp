#include <bits/stdc++.h>
using namespace std;

int binary(vector<int>& b, int s, int e, int val){
    int ans = INT_MAX;
    while(s <= e){
        int mid = s + ((e - s) >> 1) ;

        if(b[mid] >= val){
            ans = b[mid];
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return ans;
}

int binary1(vector<int>& b, int s, int e, int a_i, int prev){
    int ans = INT_MAX;
    while(s <= e){
        int mid = s + ((e - s) >> 1) ;

        if(b[mid] - a_i < a_i && b[mid] - a_i >= prev){
            ans = b[mid];
            e = mid-1;
        }
        else if(b[mid] - a_i < a_i){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return ans;
}


void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    if(n == 1){
        cout << "YES" << endl;
        return ;
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        int prev = (i == 0 ? INT_MIN : a[i - 1]);

        if (a[i] >= prev)
        {
            int x = binary1(b, 0, m-1, a[i], prev);
            if (x != INT_MAX)
            {
                a[i] = x - a[i];
            }
        }

        else
        {
            // the x which we want is >= a[i] + prev
            int x = binary(b, 0, m-1, a[i] + prev);
            a[i] = (x == INT_MAX ? 2*a[i] : x) - a[i];
            if (a[i] < prev)
            {

                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}