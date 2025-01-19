#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> adj(n);

    for(int i = 0; i < n; i++){
        cin >> adj[i];
    }

    vector<int> permutation(n);

    // left vector will store the left most range value allowed for each element
    // and right vector will store the right most range value allowed for each element
    vector<int> left(n, 0); // initially all are allowed till index 0
    vector<int> right(n, n-1); // initially all are allowed till index n-1

    for(int i = 0; i < n; i++){
        // get the count of all those elements which are in the range of i and are greater than i
        // means it has an edge with i
        int largerCount = 0;
        for(int j = 0; j < n; j++){
            if(left[j] == left[i] && right[j] == right[i] && adj[i][j] == '1'){
                largerCount++;
            }
        }

        // place the element i  in the range [l,r] left to those elements which are greater than it in it's right
        int pos = right[i] - largerCount;
        permutation[pos] = i+1; // bcoz nodes are from 1 to n and not from 0 to n-1

        // now adjust the left and right boundary of all other vertices which are in the range [l,r]
        // elements which are need left to the element i now will have their right boundary as pos-1
        // and elements to the right of pos now will have their left boundary as pos+1

        for(int j = 0; j < n; j++){
            if(left[j] == left[i] && right[j] == right[i] && i != j){
                // element that will be left to i
                if(adj[i][j] == '0'){
                    // adjust their right boundary
                    right[j] = pos-1;
                }
                // element that will be right to i
                else{
                    // adjust their left boundary
                    left[j] = pos+1;
                }
            }
        } 

        // now the left and right boundary of elmenet i will limit to pos only
        // bcoz it is placed at it's correct position
        left[i] = right[i] = pos;

    }

    for(int i : permutation) cout << i << " ";
    cout << endl;
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