#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        // base case
        if(m == 1){
            int pos = *max_element(nums.begin(), nums.end());
            int neg = *min_element(nums.begin(), nums.end());

            return max(1ll * pos * pos, 1ll * neg * neg);
        }

        // maintain the largest element from right for positive element 
        // and smallest element for negative element
        int n = nums.size();
        vector<int> largest(n, INT_MIN), smallest(n, INT_MAX);

        largest[n-1] = n-1;
        smallest[n-1] = n-1;

        for(int i = n-2; i >= 0; i--){
            if(nums[i] > nums[largest[i+1]]){
                largest[i] = i;
            }
            else largest[i] = largest[i+1];
            if(nums[i] < nums[smallest[i+1]]){
                smallest[i] = i;
            }
            else smallest[i] = smallest[i+1];
        }

        // cout << "largest" << endl;
        // for(int i : largest) cout << i << " ";
        // cout << endl;

        // cout << "smallest" << endl;
        // for(int i : smallest) cout << i << " ";
        // cout << endl;


        // m >= 2
        ll maxProduct = LLONG_MIN;
        for(int i = 0; i < n-1; i++){
            int nxtIdx = i + m-1;
            if(nxtIdx >= n) break;

            int largestEle = nums[largest[nxtIdx]], smallestEle = nums[smallest[nxtIdx]];
            maxProduct = max(maxProduct, 1ll * nums[i] * largestEle);
            maxProduct = max(maxProduct, 1ll * nums[i] * smallestEle);
            
        }
        
        //cout << maxProduct << endl;
        return maxProduct;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}