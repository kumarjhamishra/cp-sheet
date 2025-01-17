#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve(){
    ll N, K, L;
    cin >> N >> K >> L;
    double k = K;
    double l = L;
    vector<ll> a(N);

    for(ll i = 0; i < N; i++) cin >> a[i];

    double time = a[0]; // initializing time with the time first scarecrow takes to reach o
    double lastTeleportationPoint = 0; // to track the last point where the crow was teleprted
    double totalTeleportedDistance = 0;

    // iterates over each scarecrow from the 2nd scarecrow onward
    for(ll i = 1; i < N; i++){
        // potential new position for the crow using the three cases
        double newPosition = min({l, a[i]+time, max(lastTeleportationPoint+k, (a[i] - time + lastTeleportationPoint + k)/2.0)});
        time += max(0.0, newPosition - lastTeleportationPoint - k);
        totalTeleportedDistance += min(k, newPosition - lastTeleportationPoint);
        lastTeleportationPoint = newPosition;
    }

    totalTeleportedDistance += min(k, l - lastTeleportationPoint);
    cout << (int)round(2*(l - totalTeleportedDistance + a[0])) << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}