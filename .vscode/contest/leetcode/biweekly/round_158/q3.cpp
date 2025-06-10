#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
private:
    int calculatePowerof2(int num){
        int powerOf2 = 0;
        while(num && num % 2 == 0){
            powerOf2++;
            num /= 2;
        }
        return powerOf2;
    } 

    int calculateGCD(int a, int b){
        if(b == 0) return a;

        return calculateGCD(b, a % b);
    }
public:
    long long maxGCDScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        // a vector to store the power of 2 in all the elements
        vector<int> powerOf2(n, 0);

        for(int i = 0; i < n; i++){
            powerOf2[i] = calculatePowerof2(nums[i]);
        }

        ll maximumScore = 0;
        for(int i = 0; i < n; i++){
            int gcd = nums[i];
            // also count how many in this subarray has the power of 2 same as 
            // gcd will have the minimum power of 2 in this subarray from {i, ... , j}
            int minimumPowerOf2 = INT_MAX, count = 0;;
            for(int j = i; j < n; j++){
                gcd = calculateGCD(gcd, nums[j]);

                if(powerOf2[j] < minimumPowerOf2){
                    minimumPowerOf2 = powerOf2[j];
                    count = 1;
                }
                else if(powerOf2[j] == minimumPowerOf2){
                    count++;
                }

                if(count <= k){
                    // means we can increment the power of 2 by 1 in this subarray
                    maximumScore = max(maximumScore, 1ll * (j - i + 1) * gcd * 2);
                }
                else maximumScore = max(maximumScore, 1ll * (j - i + 1) * gcd);
            }

            
        }

        return maximumScore;
    }
};

int main()
{

    return 0;
}