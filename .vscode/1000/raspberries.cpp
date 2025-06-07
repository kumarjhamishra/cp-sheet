#include <bits/stdc++.h>
using namespace std;

// dp approach
/* 
int f(int i, int product, int& n, int& k, vector<int>& a, vector<vector<int>>& dp){
    // base caase
    if(product % k == 0){
        // then the minimum addtions required is 0
        return 0;
    }

    if(i == n){
        // means that the product didn't get divisible by k but the vector has ended
        return 1e9;
    }

    if(dp[i][product] != -1) return dp[i][product];


    int minimumAddition = INT_MAX;
    for(int add = 0; add < k; add++){
        int newProduct = (product * ((a[i] + add) % k)) % k;
        minimumAddition = min(minimumAddition, add + f(i+1, newProduct, n, k, a, dp));
    }

    return dp[i][product] = minimumAddition;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = (a[i] % k);
    }

    vector<vector<int>> dp(n, vector<int>(k, -1));
    cout << f(0, 1, n, k, a, dp) << endl;
    return ;
}
*/


// math approach
void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    // for k = 4 case count the number of even numbers
    //minimumOperations -> for k = 2, 3 or 5
    int countEven = 0, minimumOperations = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        minimumOperations = min(minimumOperations , (k - (a[i] % k)) % k);
        countEven += 1 - (a[i] % 2);
    }

    // handle the k = 4 explictly
    if(k == 4){
        if(n == 1){
            cout << a[0] % 4 << endl;
            return ;
        }
        else{
            cout << min(minimumOperations, max(0, 2 - countEven)) << endl;
            return ;
        }
    }

    // now the cases left are k = 2, 3, 5
    // all are prime so here we only need to make one number divisble by k
    // because they are prime so no 2 numbers can make their divisble by them until n unless one of them is divisible by it
    cout << minimumOperations << endl;
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