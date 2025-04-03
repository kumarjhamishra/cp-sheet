#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
private: 
    ll f(int i, int k, int &x, int &n, vector<ll> &movesOfEachWindow, vector<vector<ll>> &dp){
        // base case
        if(k == 0){
            // no more moves are need to be taken
            return 0;
        }
        // ki is not completed but the i did
        if(i >= n){
            return 1e15;
        }

        if(dp[i][k] != -1) return dp[i][k];

        // case of take and not take to minimize the moves
        return dp[i][k] = min(movesOfEachWindow[i] + f(i + x, k-1, x, n, movesOfEachWindow, dp), f(i+1, k, x, n, movesOfEachWindow, dp));
    }
public:
    long long minOperations(vector<int> &nums, int x, int k)
    {
        int n = nums.size();
        
        /* we will need 2 multiset in order to store the sorted elements from start till median 
        and another for next element after median till the end of window
        the size of left range can be at max 1 larger than the size of right range, in order to keep the median in the left range 
        */
       multiset<int> leftSorted, rightSorted;
       
       // maintain the left sum and right sum in order for the efficient calculation of the moves needed to convert each element of the window equal to the median
       ll leftSum = 0, rightSum = 0;
       vector<ll> movesOfEachWindow;
       for(int i = 0; i < n; i++){
            
            // index is >= x means need to shrink the window from the left side
            if(i >= x){
                // if the element at nums[i-k] is in left half remove it from there or in the right half then remove it from there
                if(leftSorted.find(nums[i - x]) != leftSorted.end()){
                    leftSum -= nums[i - x];
                    leftSorted.erase(leftSorted.find(nums[i - x]));
                }

                else{
                    rightSum -= nums[i - x];
                    // we need to give the pointer to erase to the erase function
                    rightSorted.erase(rightSorted.find(nums[i - x]));
                }
            }

            /*
            now add the current element 
            if the size of left range <= size of right range insert in the left range 
            else insert in the right range
            */
            if(leftSorted.size() <= rightSorted.size()){
                leftSum += nums[i];
                leftSorted.insert(nums[i]);
            }
            else{
                rightSum += nums[i];
                rightSorted.insert(nums[i]);
            }

            /*
            due to changing size of the window it can happen that those elements which should be in left range are currently in right range and vice versa
            so we need to rearrange the elements properly

            the last element of the left range shoudl be <= the first element of the right range, until this is not acheived keep rearranging
            */
            int lastOfLeftRange = *leftSorted.rbegin();
            int firstOfRightRange = *rightSorted.begin();
            while(!leftSorted.empty() && !rightSorted.empty() && lastOfLeftRange > firstOfRightRange){
                leftSum -= lastOfLeftRange;
                leftSum += firstOfRightRange;
                rightSum -= firstOfRightRange;
                rightSum += lastOfLeftRange;

                leftSorted.erase(leftSorted.find(lastOfLeftRange));
                rightSorted.erase(rightSorted.find(firstOfRightRange));
                leftSorted.insert(firstOfRightRange);
                rightSorted.insert(lastOfLeftRange);

                // update the pointers
                lastOfLeftRange = *leftSorted.rbegin();
                firstOfRightRange = *rightSorted.begin();
            }

            // when a window size is completed and is of size x
            if(i >= x-1){
                int median = *leftSorted.rbegin();
                // count of elements in the left range and in the right range
                int leftCount = leftSorted.size(), rightCount = rightSorted.size();
                ll moves = 1ll * (1ll * median * leftCount - leftSum) + 1ll * (rightSum - 1ll * median * rightCount);
                movesOfEachWindow.push_back(moves);
            }

        }

        
        int sizeOfMovesStorage = movesOfEachWindow.size();
        vector<vector<ll>> dp(sizeOfMovesStorage, vector<ll>(k+1, -1));
        return f(0, k, x, sizeOfMovesStorage, movesOfEachWindow, dp);
    }


};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {9,-2,-2,-2,1,5};
    int x = 2, k = 2;
    cout << sol.minOperations(nums, x, k);
    
    return 0;
}