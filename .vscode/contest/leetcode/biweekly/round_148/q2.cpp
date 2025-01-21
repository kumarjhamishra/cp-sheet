#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        if(arr == brr) return 0;
        ll n = arr.size();
        if(n == 1) return abs(arr[0] - brr[0]);

        ll cost1 = 0;
        for(ll i = 0; i < n; i++){
            cost1 += abs(arr[i] - brr[i]);
        }

        // 0 means not ordered, 1 means inc ordered and 2 means dec ordered
        // another variable -> 1 means increasingly ordered and 2 means decreasingly
        int order1 = 1;

        // traversing arr with assumption that it is increasing
        for(int i = 1; i < n; i++){
            if(arr[i] < arr[i-1]){
                order1 = 0;
                break;
            }
        }
        if(order1 == 0){
            // now check with taking assumption that it is decreasing
            order1 = 2;
            for(int i = 1; i < n; i++){
                if(arr[i] > arr[i-1]){
                    order1 = 0;
                    break;
                }
            }
        }

        int order2 = 1;
        // traversing brr with assumption that it is increasing
        for(int i = 1; i < n; i++){
            if(brr[i] < brr[i-1]){
                order2 = 0;
                break;
            }
        }
        if(order2 == 0){
            // now check with taking assumption that it is decreasing
            order2 = 2;
            for(int i = 1; i < n; i++){
                if(brr[i] > brr[i-1]){
                    order2 = 0;
                    break;
                }
            }
        }

        
        ll cost2 = 0;
        if(order1 == 0 || order2 == 0 || order1 != order2){
            sort(arr.begin(), arr.end());
            sort(brr.begin(), brr.end());
            cost2 += k;
        }

        

        for(ll i = 0; i < n; i++){
            cost2 += abs(arr[i] - brr[i]);
        }

        ll finalCost = min(cost1, cost2);
        cout << finalCost << endl;
        return finalCost;
        
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        //solve();
    }

    return 0;
}