#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;

    int x = a1 + a2;
    int y = a4 - a2;
    int z = a5 - a4;

    set<int> st;
    st.insert(x);
    st.insert(y);
    st.insert(z);

    cout << 3 - st.size() + 1 << endl;
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