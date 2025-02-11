#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> assigned;
    void f(int idx, int num, unordered_map<int, int>& mpElement){
        // we can find all the divisors of num in root(num) time
        // if i is a divisor of num then num/i is also a divisor of num

        for(int i = 1; i <= sqrt(num); i++){
            int divisor = i;
            if(num % i != 0) continue;

            if(mpElement.find(divisor) != mpElement.end()) assigned[idx] = min(assigned[idx], mpElement[divisor]);
            
            // the second divisor is num / i
            divisor = num / i;
            if(mpElement.find(divisor) != mpElement.end()) assigned[idx] = min(assigned[idx], mpElement[divisor]);
        }

        if(assigned[idx] == INT_MAX) assigned[idx] = -1;

        return ;
    }
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        int n = groups.size();
        assigned.resize(n, INT_MAX);

        // make the mapping of each unique element of elements with left most index where it is found
        unordered_map<int, int> mpElement;

        for(int i = elements.size()-1; i >= 0; i--) mpElement[elements[i]] = i;

        for(int i = 0; i < groups.size(); i++){
            f(i, groups[i], mpElement);
        }

        return assigned;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}