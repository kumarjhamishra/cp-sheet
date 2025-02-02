#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;

        // get all the gaps
        int pe = 0;
        for(int i = 0; i < startTime.size(); i++){
            gaps.push_back(startTime[i] - pe);
            pe = endTime[i];
        }
        gaps.push_back(eventTime - pe);
        
        // move k meetings to get k+1 free time gaps together
        int currTime = 0, maxFreeTime = 0;
        for(int i = 0; i < gaps.size(); i++){
            currTime += gaps[i];
            if(i >= k+1) currTime -= gaps[i - (k+1)];
            maxFreeTime = max(maxFreeTime, currTime);
        }

        return maxFreeTime;
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