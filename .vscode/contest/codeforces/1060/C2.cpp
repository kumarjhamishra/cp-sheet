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

const int MAXI = 2e5+10;

vvi primeFactors(MAXI);

void precomputePrimeFactors(){
    for(int i = 2; i < MAXI; i++){
        // i is not a prime factor
        if(!primeFactors[i].empty()) continue;

        for(int j = i; j < MAXI; j += i){
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

    ll minimumCost = LLONG_MAX;

    // store the frequency of every prime number as a factor along with that check if 
    // if any prime number occurences becomes > 1 -> common factor
    map<int, int> cnt;
    for(int ele : a){
        for(int prime : primeFactors[ele]){
            cnt[prime]++;
            if(cnt[prime] > 1){
                minimumCost = 0;
            }
        }
    }

    if(minimumCost == 0){
        // cout << "first if: " << 0 << endl;
        cout << 0 << endl;
        return ;
    }

    // now check if by incrementing any num by 1 creates a common prime factor
    // along with maintaining the minimum cost
    for(int i = 0; i < n; i++){
        int ele = a[i];

        for(int prime : primeFactors[ele]){
            cnt[prime]--;
        }

        for(int prime : primeFactors[ele+1]){
            if(cnt[prime] > 0){
                minimumCost = min(minimumCost, 1ll*b[i]);
            }
        }

        for(int prime : primeFactors[ele]){
            cnt[prime]++;
        }
    }

    // if(minimumCost != LLONG_MAX){
    //     cout << "second if: "  << minimumCost << endl;
    //     // cout << minimumCost << endl;
    //     return ;
    // }


    // now there is no other way other than selecting 2 num's with lowest cost, incrementing them
    // and making their gcd = 2

    // and one last case:
    // if cost of incrementing the num with lowest cost multiple times < sum of 2 lowest cost
    // eg - 1*4 < 1 + 15

    ll c1 = -1, c2 = -1;
    int idx = -1; // idx of smallest cost
    for(int i = 0; i < n; i++){
        if(c1 == -1 || b[i] < c1){
            c2 = c1;
            c1 = b[i];
            idx = i;
        }
        else if(c2 == -1 || b[i] < c2) c2 = b[i];
    }

    //cout << "final: "  << c1 + c2 << endl;
    minimumCost = min(minimumCost, c1 + c2);

    // checking last case
    for(int i = 0; i < n; i++){
        if(i == idx) continue;

        int ele = a[i];
        for(int prime : primeFactors[ele]){
            // to make the num a[idx] divisible with prime the increment required in a[idx] is
            // prime - ((a[idx] + prime) mod prime)
            int increments = prime - ((a[idx] + prime) % prime);
            minimumCost = min(minimumCost, 1ll * c1 * increments);
        }
    }

    // cout << "final: "  << minimumCost << endl;
    cout << minimumCost << endl;
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