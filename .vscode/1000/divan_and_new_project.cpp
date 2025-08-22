#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve(){
    int n;
    cin >> n;

    vector<pii> a(n);
    for(int i = 0; i < n; i++){
        int times;
        cin >> times;
        a[i] = {times, i+1};
    }

    sort(a.begin(), a.end(), greater<pii>());
    vi x_cod(n+1);

    int cod = 0;
    ll minimumTime = 0;
    x_cod[0] = cod++;
    for(int i = 0; i < n; i++){
        x_cod[a[i].second] = cod;
        minimumTime += (a[i].first * 2ll * abs(x_cod[0] - cod));
        cod *= -1;
        if(cod > 0) cod += 1;
    }

    cout << minimumTime << endl;
    for(int i : x_cod){
        cout << i << " ";
    }
    cout << endl;
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