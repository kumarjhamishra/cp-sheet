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

//#define pb push_back

void solve(){
    int n;
    cin >> n;

    int winners = n, losers = 0, totalMatches = 0;
    while(winners != 1 || losers != 1){
        // for 1 round

        // calculate matches took place in winner's group
        totalMatches += winners/2;
        // those who looses in winner's group
        int loses = winners/2;
        winners = winners/2 + winners % 2;

        // calculate matches took place in looser's group
        totalMatches += losers/2;


        // now total losers for the next round
        losers = losers/2 + losers%2 + loses;
    }

    totalMatches++;
    cout << totalMatches << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}