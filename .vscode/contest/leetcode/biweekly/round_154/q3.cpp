#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {   
        int n = nums.size();
        // base case
        if(n <= 2) return n;
        set<int> pairXor, tripletXor;
        vector<int> pairtaken(1e5, -1), triplettaken(1e5, -1);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int _xor = (nums[i] ^ nums[j]);
                if(pairtaken[_xor] == -1){
                    pairXor.insert(_xor);
                    pairtaken[_xor] = 1;
                }
            }
        }

        for(int pairVal : pairXor){
            for(int i = 0; i < n; i++){
                int triplet = (pairVal ^ nums[i]);
                if(triplettaken[triplet] == -1){
                    tripletXor.insert(triplet);
                    triplettaken[triplet] = 1;
                }
            }
        }

        return tripletXor.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {6, 7, 8, 9};
    cout << sol.uniqueXorTriplets(nums) << endl;

    return 0;
}