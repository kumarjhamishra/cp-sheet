#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<int> linkedA(n), linkedB(n);
    unordered_map<int, int> hashA, hashB;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            linkedA[i] = a[i];
            linkedB[i] = b[i];
            hashA[a[i]] = i;
            hashB[b[i]] = i;
        }
        else{
            linkedA[i] = b[i];
            linkedB[i] = a[i];
            hashA[b[i]] = i;
            hashB[a[i]] = i;
        }
    }

    cout << "printing linked a and b" << endl;
    for(int i = 0; i < n; i++){
        cout << linkedA[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << linkedB[i] << " ";
    }
    cout << endl;


    for(int i = n-1; i >= 0; i--){
        if(linkedA[i] == linkedB[i]){
            cout << i+1 << endl;
            return ;
        }
        // got that number in their link only 
        // eg - a[i] got b[i] in it's own link or vice versa
        if((hashA.count(linkedB[i]) && hashA[linkedB[i]] > i) || (hashB.count(linkedA[i]) && hashB[linkedA[i]] > i)){
            cout << i+1 << endl;
            return ;
        }

        // a[i] foound b[i] but in the b's list so need to delte one index
        if((hashB.count(linkedB[i]) && hashB[linkedB[i]] > i+1) || (hashA.count(linkedA[i]) && hashA[linkedA[i]] > i+1)){
            cout << i+1 << endl;
            return ;
        }

        if((hashB.count(linkedB[i]) && hashB[linkedB[i]] > i) || (hashA.count(linkedA[i]) && hashA[linkedA[i]] > i)){
            cout << i << endl;
            return ;
        }


    }

    cout << 0 << endl;
    return ;
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