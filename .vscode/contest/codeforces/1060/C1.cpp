#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define pb push_back

// int gcd(int a, int b){
//     if(b == 0) return a;
//     return gcd(b, a % b);
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     vi a(n), b(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < n; i++)
//         cin >> b[i];

//     int minCost = INT_MAX;
//     // check for pair i and i+1
//     for (int i = 0; i < n - 1; i++)
//     {
//         int currCost = 0, c = a[i], d = a[i + 1];
//         // if (c == 1)
//         // {
//         //     currCost++;
//         //     c++;
//         // }
//         // if (d == 1)
//         // {
//         //     currCost++;
//         //     d++;
//         // }

//         // // both even
//         // if(c % 2 == 0 && d % 2 == 0){
//         //     // no extra cost - bcoz gcd always > 1 -> minimum 2
//         //     minCost = min(minCost, currCost);
//         // }

//         if (__gcd(c, d) <= 1)
//         {
//             if (__gcd(c + 1, d) > 1 || __gcd(c, d + 1) > 1)
//                 currCost += 1;
//             else
//                 currCost += 2;
//         }

//         minCost = min(minCost, currCost);

//         if (minCost == 0)
//         {
//             cout << minCost << endl;
//             return;
//         }
//     }

//     cout << minCost << endl;
//     return;
// }



const int MAXI = 2e5+10;

vvi primeFactors(MAXI+1);

// 1. precompute all the prime factors of each number
void precomputePrimeFactors(){
    for(int i = 2; i <= MAXI; i++){
        // i should be the prime factor
        if(!primeFactors[i].empty()) continue;

        for(int j = i; j <= MAXI; j += i){
            primeFactors[j].push_back(i);
        }
    }
}


void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);

    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    
    // max ans can be 2
    int ans = 2;

    map<int, int> cnt;
    //2. checking if already 2 numbers share a common prime factor
    for(int i = 0; i < n; i++){
        for(int prime : primeFactors[a[i]]){
            cnt[prime]++;
            if(cnt[prime] > 1) ans = 0;
        }
    }

    if(ans == 0){
        cout << ans << endl;
        return ;
    }


    //3. now check if incrementing any one number with 1 can make it's any prime factor
    // common with some other already existing number

    for(int i = 0; i < n; i++){
        // removing the effect of a[i] to correctly evaluate for a[i]+1
        for(int prime : primeFactors[a[i]]) cnt[prime]--;

        for(int prime : primeFactors[a[i] + 1]){
            // some other number already has this prime as it's factor
            if(cnt[prime] > 0) ans = 1;
        }

        // restating a[i]'s effect
        for(int prime : primeFactors[a[i]]) cnt[prime]++;
    }

    cout << ans << endl;
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precomputePrimeFactors();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}