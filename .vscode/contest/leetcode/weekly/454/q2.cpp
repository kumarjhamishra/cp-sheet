#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> totalCount, leftCount;

        int n = nums.size();
        for(int i = 0; i < n; i++) totalCount[nums[i]]++;

        leftCount[nums[0]] = 1;
        ll triplets = 0;
        for(int i = 1; i < n-1; i++){
            int required = nums[i] * 2;
            int leftFreq = leftCount[required], rightFreq = totalCount[required] - leftCount[required];
            if(required == nums[i]) rightFreq -= 1;
            if(leftFreq > 0 && rightFreq > 0){
                triplets = (triplets + (1ll * leftFreq * rightFreq) % mod) % mod;
            }

            leftCount[nums[i]]++;
        }
        //cout << triplets << endl;
        return (int)triplets;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    
    return 0;
}