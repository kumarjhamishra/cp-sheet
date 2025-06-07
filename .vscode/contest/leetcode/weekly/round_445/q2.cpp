#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.size();
        if(n == 1) return s;

        //sort(s.begin(), (s.begin() + (n - 1)/2));
        string half;
        for(int i = 0; i <= (n - 1)/2; i++){
            half.push_back(s[i]);
        }

        // odd size, there is a chance that the mid element would have the freq 1 or odd
        // so that element will always be in the middle
        int end = (n-1)/2;
        if(n % 2 == 1){
            half.pop_back();
            end -= 1;
        }
        sort(half.begin(), half.end());
        // cout << "half" << endl;
        // cout << half << endl;

        
        for(int i = 0; i <= end; i++){
            s[i] = half[i];
            s[n-i-1] = s[i];
        }

        return s;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "daccad";
    cout << sol.smallestPalindrome(s);

    return 0;
}