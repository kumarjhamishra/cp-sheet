#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

class Solution
{
private:
    bool isValid(vector<int> &points, int &m, ll target, ll& n){
        ll moves = 0;

        ll advanceMovesForNext = 0, normalMove = 0;

        for(ll i = 0; i < n && moves <= m; i++){
            // find the moves required
            ll gamePoint = points[i];
            ll games = ceil((double)target / gamePoint);

            if(advanceMovesForNext >= games){
                advanceMovesForNext = 0;
                normalMove += 1;
            }
            else{
                ll pointsAlreadyCovered = advanceMovesForNext * gamePoint;
                games = ceil((double)(target - pointsAlreadyCovered) / gamePoint);
                moves += 2 * games - 1;
                advanceMovesForNext = max(games - 1 , 0ll);
                moves += normalMove;
                normalMove = 0;
            }
        }

        return moves <= 1ll * m;
    }
public:
    long long maxScore(vector<int> &points, int m)
    {
        ll n = points.size();

        ll l = 0, r = 1e15; // 10^9 * 10^6
        ll ans = 0;
        while(l <= r){
            ll mid = l + ((r - l) >> 1);
            if(isValid(points, m, mid, n)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> points = {};
    int m;
    sol.maxScore(points, m);

    return 0;
}