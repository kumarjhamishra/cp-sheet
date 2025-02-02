#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        // find the prefix and suffix max gap for each meeting block to check if we can place it in an another free time gap block 
        int prefixMaxTime = 0, prevEnd = 0, n = startTime.size();
        vector<int> preMax(n, 0), suffMax(n, 0);
        for(int i = 0; i < startTime.size(); i++){
            prefixMaxTime = max(prefixMaxTime, startTime[i] - prevEnd);
            preMax[i] = prefixMaxTime;
            prevEnd = endTime[i];
        }

        int nextStartTime = eventTime, suffixMaxTime = 0;
        for(int i = n-1; i >= 0; i--){
            suffixMaxTime = max(suffixMaxTime, nextStartTime - endTime[i]);
            suffMax[i] = suffixMaxTime;
            nextStartTime = startTime[i];
        }

        // now process the gaps
        // if we can place the meeting time block to any other free time gap either in left or right then total time will be 
        // left gap + right gap + curr block time
        // else only left gap + right gap

        int maxFreeTime = 0, currFreeTime = 0;
        for(int i = 0; i < n; i++){
            // add the left gap time
            currFreeTime += (i >= 1 ? startTime[i] - endTime[i-1] : startTime[i] - 0);
            // add the right gap time
            currFreeTime += (i <= n-2 ? startTime[i+1] - endTime[i] : eventTime - endTime[i]);

            // to add the curr meeting block either the suff[i+1] >= curr meeting block or the pre[i-1] >= curr meeting block
            int currMettingBlock = endTime[i] - startTime[i];
            if((i <= n-2 && suffMax[i+1] >= currMettingBlock) || (i >= 1 && preMax[i-1] >= currMettingBlock)) currFreeTime += currMettingBlock;

            maxFreeTime = max(maxFreeTime, currFreeTime);
            currFreeTime = 0;
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