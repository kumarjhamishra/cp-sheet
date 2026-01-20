#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpllll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define pb push_back

vpllll calculateForbiddenRegion(vll& a, ll& t, ll& n, ll& x, ll& k){
    // forbidden region: [max(0, a_i-t+1), min(x, a_i+t-1)]
    vpllll forbidden;
    for(int i = 0; i < n; i++){
        ll s = max(0ll, a[i]-t+1), e = min(x, a[i]+t-1);
        if(s <= e) forbidden.push_back({s, e});
    }

    // if no spots are forbidden, check if there are enough total spots[0, x]
    if(forbidden.empty()){
        return {};
    }

    sort(forbidden.begin(), forbidden.end());

    // merge overlapping zones
    vpllll nonOverlapping;
    nonOverlapping.push_back(forbidden[0]);
    for(size_t i = 1; i < forbidden.size(); i++){
        if(forbidden[i].first <= nonOverlapping.back().second + 1){
            nonOverlapping.back().second = max(nonOverlapping.back().second, forbidden[i].second);
        }
        else{
            nonOverlapping.push_back(forbidden[i]);
        }
    }

    return nonOverlapping;
}

bool isPossible(ll t, vll& a, ll& n, ll& x, ll& k){
    // t = 0 case: always possible if enought spots exist
    if(t == 0){
        return (x+1) >= k;
    }

    // calculate the forbidden zones for each a_i where no teleport can 
    // be placed to make the minimum distance as t valid

    vpllll nonOverlapping = calculateForbiddenRegion(a, t, n, x, k);
    if(nonOverlapping.empty()){
        // if no spots are forbidden, check if there are enough total spots [0, x]
        return (x+1) >= k;
    }

    // before analysing the total valid points to place teleports is x+1 (0 to x)
    ll validPositions = x+1;
    // now find the total valid positions where we can place k teleports accoding to the non overlapping forbidden zones
    for(auto i : nonOverlapping){
        validPositions -= (i.second - i.first + 1);
    }

    return validPositions >= k;
}

void solve(){
    int _n, _k, _x;
    cin >> _n >> _k >> _x;

    ll n = _n, k = _k, x = _x;
    vll a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());

    // maximize the minimum problem - BS on answer
    // maximise the minimum dist T, T: minimum distance between any a_i and it's nearest teleport
    // T ranges from 0 to x

    ll l = 0, h = x, t_opt = -1;
    while(l <= h){
        ll mid = l + ((h-l) >> 1);
        
        // check if t_opt can be mid 
        if(isPossible(mid, a, n, x, k)){
            t_opt = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    //cout << "t_opt: " << t_opt << endl;


    // placing the k teleports at valid positions
    // recalculate the forbidden zones - to get the non overlapping forbidden zones for t_opt where 
    // we can't place a teleporter
    vpllll nonOverlapping = calculateForbiddenRegion(a, t_opt, n, x, k);
    
    // //cout << "non-overlapping intervals" << endl;
    // for(auto i : nonOverlapping){
    //     cout << i.first << " " << i.second << endl;
    // }

    // If no forbidden regions, just place k teleports starting from 0

    if(nonOverlapping.empty()){
        for(ll i = 0; i < k; i++){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    
    // place teleports in allowed regions
    ll currentPos = 0;
    
    for(ll i = 0; i < nonOverlapping.size() && k > 0; i++){
        ll end = nonOverlapping[i].first - 1;
        while(currentPos <= end && k > 0){
            cout << currentPos << " ";
            currentPos++;
            k--;
        }
        // move past the forbidden region
        currentPos = nonOverlapping[i].second + 1;
    }

    // place remaining teleports after all forbidden regions
    while(k--){
        cout << currentPos++ << " ";
    }
    cout << endl;
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