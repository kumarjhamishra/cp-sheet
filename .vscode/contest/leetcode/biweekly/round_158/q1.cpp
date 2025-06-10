#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumDistinctTriplet(vector<int> &x, vector<int> &y)
    {
        unordered_map<int, priority_queue<int>> mp;

        for(int i = 0; i < x.size(); i++){
            mp[x[i]].push(y[i]);
        }

        if(mp.size() < 3) return -1;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto i : mp){
            minHeap.push(i.second.top());
            if(minHeap.size() > 3){
                minHeap.pop();
            }
        }

        int sum = 0;
        while(!minHeap.empty()){
            sum += minHeap.top();
            minHeap.pop();
        }

        return sum;
    }
};

int main()
{

    return 0;
}