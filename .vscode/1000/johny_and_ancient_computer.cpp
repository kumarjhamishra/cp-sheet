#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve()
{
    ll A, B;
    cin >> A >> B;

    ll a = min(A, B), b = max(A, B);
    // base check
    if (b % a)
    {
        cout << -1 << endl;
        return;
    }

    //cout << "b: " << b << " a: " << a << endl;
    ll quotient = b / a, powerCount = 0;
    //cout << "quotient: " << quotient << endl;
    while (true)
    {
        ll twoPower = (1ll << powerCount);
        if (quotient == twoPower)
        {
            break;
        }
        else if (quotient > twoPower)
        {
            powerCount++;
        }
        // quotient is not a power of two
        else
        {
            powerCount = -1;
            break;
        }
    }

    // can't be made with multiplying with 8,4 or 2
    if (powerCount == -1)
    {
        cout << -1 << endl;
        return;
    }

    ll operations = 0;
    //cout << "powerCount: " << powerCount << endl;
    if (powerCount >= 3)
    {
        operations += powerCount / 3;
        powerCount %= 3;
    }
    if (powerCount >= 2)
    {
        operations += powerCount / 2;
        powerCount %= 2;
    }
    if (powerCount >= 1)
    {
        operations += powerCount / 1;
        powerCount %= 1;
    }
    cout << operations << endl;
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