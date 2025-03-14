#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution
{
private:
    int mod2_cal(int n, int k)
    {
        int res = 1;
        while (n > 0 || k > 0)
        {
            int a = n % 2;
            int b = k % 2;
            if (b > a)
                return 0;
            n /= 2;
            k /= 2;
        }
        return res;
    }

    int mod5_cal(int n, int k)
    {
        int mod5_comb[5][5] = {
            {1, 0, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {1, 2, 1, 0, 0},
            {1, 3, 3, 1, 0},
            {1, 4, 1, 4, 1}};
        int res = 1;
        while (n > 0 || k > 0)
        {
            int a = n % 5;
            int b = k % 5;
            if (b > a)
                return 0;
            res = (res * mod5_comb[a][b]) % 5;
            n /= 5;
            k /= 5;
        }
        return res;
    }

public:
    bool hasSameDigits(string s)
    {
        int m = s.size() - 2;
        if (m < 0)
        {
            return s.size() == 2 ? (s[0] == s[1]) : false;
        }

        int crt_table[2][5] = {
            {0, 6, 2, 8, 4},
            {5, 1, 7, 3, 9}};

        
        vector<int> coeff(m + 1);
        for (int i = 0; i <= m; ++i)
        {
            int mod2 = mod2_cal(m, i);
            mod2 = mod2 ? 1 : 0;
            int mod5 = mod5_cal(m, i);
            mod5 = (mod5 % 5 + 5) % 5;
            coeff[i] = crt_table[mod2][mod5];
        }
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i <= m; ++i)
        {
            int d = s[i] - '0';
            sum1 += coeff[i] * d;
            d = s[i + 1] - '0';
            sum2 += coeff[i] * d;
        }
        sum1 %= 10;
        sum2 %= 10;
        return sum1 == sum2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
    }

    return 0;
}