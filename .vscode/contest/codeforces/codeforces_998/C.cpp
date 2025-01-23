#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    // maintain the frequency of each number
    vector<int> frequency(n+1, 0);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        frequency[num]++;
    }

    // rounds will be n/2
    int score = 0;
    for(int i = 1; i <= n; i++){
        int num1 = i;
        int num2 = k-i;
        // check if num2 is in range and valid
        if(num2 < 1 || num2 > n) continue;
        if(frequency[num1] == -1 || frequency[num2] == -1) continue;

        if(num1 == num2) score += frequency[num2]/2;
        else score += min(frequency[num1], frequency[num2]);

        frequency[num1] = frequency[num2] = -1;
    }

    cout << score << endl;
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