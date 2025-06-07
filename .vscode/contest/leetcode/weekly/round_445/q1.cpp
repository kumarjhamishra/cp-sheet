#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int a = abs(x - z), b = abs(y - z);

        if(a < b) return 1;
        if(a > b) return 2;
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    

    return 0;
}