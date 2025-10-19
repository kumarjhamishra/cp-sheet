#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define pb push_back

void solve(){
    /*
    Instead of carefully choosing all k
        elements individually, it is sufficient to pick three distinct integers x
        , y
        , and z
        and repeat them cyclically — that is, append

        x,y,z,x,y,z,…
        until we perform k
        operations. For n≥3
        , we can always find such x
        , y
        , z
        that add no extra palindromic subarrays.

        Now let's try to find such integers x
        , y
        , z
        . There will be two cases.

        Case 1: a
        is a permutation of 1,2,3,…,n
        .

        If the array a
        is a permutation, we can simply choose the first three elements of a
        for the construction. That is, let x=a1
        , y=a2
        , and z=a3
        . Since all elements in a permutation are distinct, these choices guarantee that x
        , y
        , and z
        are distinct and add no extra palindromic subarrays.

        Case 2: a
        is not a permutation of 1,2,3,…,n
        .

        If the array a
        is not a permutation, we can choose x
        to be any integer that does not appear in a
        . Let z
        be the last element of the array, and choose y
        as any integer different from both x
        and z
        . These three numbers will always be distinct and add no extra palindromic subarrays.

        Time Complexity: O(n+k)
        per testcase.
    */

    int n, k;
    cin >> n >> k;

    vi a(n), cnt(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    // check if a is permutation
    int x = -1;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0){
            x = i; // x will be that number whose count is 0
            break;
        }
    }

    if(x == -1){
        for(int i = 0; i < k; i++){
            cout << a[n-3 + (i % 3)] << " ";
        }
        cout << endl;
    }
    else{
        // choosing y not equal to x and not equal to the last element (which will be our z)
        int y = -1;
        for(int i = 1; i <= n; i++){
            if(i != x && i != a[n-1]){
                y = i;
                break;
            }
        }

        vi v = {x, y, a[n-1]};
        for(int i = 0; i < k; i++){
            cout << v[i % 3] << " ";
        }
        cout << endl;
    }
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