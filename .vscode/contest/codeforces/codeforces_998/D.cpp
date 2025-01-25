#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    bool isSorted = true;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i > 0 && nums[i] < nums[i - 1])
            isSorted = false;
    }

    if (isSorted)
    {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i <= n - 2; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
        nums[i + 1] -= nums[i];
        nums[i] -= nums[i];
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