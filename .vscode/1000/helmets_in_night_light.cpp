#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool compare(const pii& x, const pii& y){
    if(x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

void solve(){
    int n, p;
    cin >> n >> p;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    // making a vector of pair of cost bi and maximum people ai, and will be sorted in the order of
    // minimum cost and for minimum costs and maximum people

    vector<pii> costAndPeople;
    for(int i = 0; i < n; i++) costAndPeople.push_back({b[i], a[i]});

    sort(costAndPeople.begin(), costAndPeople.end(), compare);

    int peopleCovered = 1;
    ll minimumCost = p;
    for(int i = 0; i < n; i++){
        int cost = costAndPeople[i].first;
        if(cost > p) break;
        int maxPeople = costAndPeople[i].second;

        // no of people to which this person will announce the news
        int people = min(maxPeople, n - peopleCovered);
        minimumCost += 1ll * cost * people;
        peopleCovered += people;

        if(peopleCovered == n) break;
    }

    if(peopleCovered < n){
        minimumCost += 1ll * p * (n - peopleCovered);
    }

    cout << minimumCost << endl;
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