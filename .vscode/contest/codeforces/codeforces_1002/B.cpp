#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int s = 0, e = n - 1 - (k-1);
    vector<int> sub;
    for(int subArr = 1; subArr <= k; subArr++){
        if(subArr % 2 != 0) s++;
        else{
            e = n - 1 - (k-subArr);
            int pos = sub.size() + 1;
            //bool found
            unordered_map<ll, ll> mp;
            for(int i = s; i < n && i <= e; i++){
                mp[1ll*a[i]]++;
            }

            if(mp.count(pos) && mp[pos] > 1){
                //cout << "ans" << endl;
                cout << pos+1 << endl;
                return;
            }
            else if((mp.count(pos) && mp.size() > 1) || (mp.find(pos) == mp.end())){
                //cout << "ans" << endl;
                cout << pos << endl;
                return;
            }

            sub.push_back(a[s]);
            s++;
        }
    }

    sub.push_back(0);
    //cout << "ans" << endl;
    cout << sub.size() << endl;
    return ;
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