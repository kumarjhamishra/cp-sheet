#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// reference solution - https://leetcode.com/problems/count-substrings-divisible-by-last-digit/solutions/6395865/c-number-theory-digit-by-digit

class Solution
{
public:
    long long countSubstrings(string s)
    {
        ll n = s.size();
        vector<ll> mod9(9, 0), mod7(7, 0), temp(9, 0);

        auto addMod9 = [&](int add)
        {
            for (int i = 0; i < 9; i++)
            {
                temp[(i + add) % 9] = mod9[i];
            }

            mod9 = temp;
        };

        auto addDigitMod7 = [&](int digit)
        {
            for (int i = 0; i < 7; i++)
                temp[i] = 0;

            for (int i = 0; i < 7; i++)
            {
                temp[(10 * i + digit) % 7] = mod7[i];
            }

            for (int i = 0; i < 7; i++)
                mod7[i] = temp[i];
        };

        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll digit = s[i] - '0';

            if (digit > 0)
            {

                // each digit will divide itself so 1 substring
                ans++;

                // for the substrings ending at 1, 2, 5 all the substrings will be counted bcoz all will be divisible
                if (digit == 1 || digit == 2 || digit == 5)
                {
                    ans += i;
                }

                // for divisibility with 3 sum divisible by 3
                // for divisibility with 6 divisibility with 2 (always true here) and divisibility with 3
                else if (digit == 3 || digit == 6)
                {
                    // here we can also use the answers for 9 bcoz a number divisible by 9 will sure shot be divisbile by 3
                    ans += mod9[0] + mod9[3] + mod9[6];

                    // remainder -> 0 + num 3 -> total digit sum divisible by 3
                    // remainder -> 3 + num 3 = 6 -> total digit sum divisible by 3
                    // remainder -> 6 + num 3 = 9 -> total digit sum divisible by 3
                }

                // last 2 digits divisible by 4
                else if (digit == 4)
                {
                    if (i > 0)
                    {
                        ll last2 = 10 * (s[i - 1] - '0') + 4;
                        ans += last2 % 4 == 0 ? i : 0;
                    }
                }

                // divisibility with 7
                else if (digit == 7)
                {
                    // all the previous substrings which are divisible 7
                    // explaination is in the solution link
                    ans += mod7[0];
                }

                // last 3 digits divisible by 8
                else if (digit == 8)
                {
                    if (i > 0)
                    {
                        ll last2 = 10 * (s[i - 1] - '0') + 8;
                        ans += last2 % 8 == 0 ? 1 : 0;
                        if (i >= 2)
                        {
                            ll last3 = 100 * (s[i - 2] - '0') + last2;
                            ans += last3 % 8 == 0 ? i - 1 : 0;
                        }
                    }
                }

                else if (digit == 9)
                    ans += mod9[0];
            }

            addMod9(digit);
            addDigitMod7(digit);
            mod9[digit % 9]++;
            mod7[digit % 7]++;

            //cout << ans << endl;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "057";
    cout << sol.countSubstrings(s) << endl;

    return 0;
}