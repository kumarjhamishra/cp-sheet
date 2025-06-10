#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // a vector which will store for each index that at what next index it will get the same value as itself
    vector<int> next(n, -1);
    // a vector which will act a hash map for each unique value
    vector<int> hash(n+1, -1);

    for(int i = n-1; i >= 0; i--){
        if(hash[a[i]] == -1){
            next[i] = i;
        }
        else{
            next[i] = hash[a[i]];
        }
        hash[a[i]] = i;
    }

    vector<int> farthest(n+1, -1);
    for(int i = 0; i < n; i++){
        farthest[a[i]] = i;
    }

    int segments = 0, i = 0, prevEnd = 0;
    while(i < n){
        if(next[i] == i){
            segments++;
            break;
        }
        else{
            int nextStart = next[i];
            bool isLast = false;
            for(int j = prevEnd+1; j < i; j++){
                if(next[j] == j){
                    isLast = true;
                    break;
                }
                else if(farthest[a[j]] <= i){
                    // can't do partition here
                    isLast = true;
                    break;
                }
                nextStart = max(nextStart, next[j]);
            }
            if(isLast){
                segments++;
                break;
            }

            segments++;
            prevEnd = i;
            i = nextStart;
        }
    }

    cout << segments << endl;
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