#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        
        int end = n / 4;
        int oddDays = (end + 1) / 2;
        int evenDays = end - oddDays;
        
        long long totalWghtGain = 0;
        int l = n - 1;
        int r = 0;
        
        for (int i = 0; i < oddDays; i++) {
            totalWghtGain += pizzas[l];
            l--;
            r += 3;
        }
        for (int i = 0; i < evenDays; i++) {
            l--;
            int second = pizzas[l];
            l--;
            totalWghtGain += second;
            r += 2;
        }
        return totalWghtGain;

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> pizzas = {2,1,1,1,1,1,1,1};
    cout << sol.maxWeight(pizzas);
    return 0;
}