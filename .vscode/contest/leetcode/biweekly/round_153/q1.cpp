#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    int reverseDegree(string s)
    {
        ll ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans += (i + 1) * ( 26 - (s[i] - 'a'));
        }

        return (int)ans;

    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "zaza";
    Solution sol;
    cout << sol.reverseDegree(s) << endl;

    return 0;
}