/*
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;

class Solution
{
public:
    vector<int> longestCommonPrefix(vector<string> &words)
    {
        if (words.size() == 1)
            return {0};

        // we will store the prefix string for all pairs i and i+1
        vs longestPrefixes;
        unordered_map<int, int> freq; // {length -> freq}
        priority_queue<int> maxHeap;
        int n = words.size();
        for (int i = 0; i < n - 1; i++)
        {
            string pre = "";
            int j = 0, k = 0;
            while (j < words[i].size() && k < words[i + 1].size() && words[i][j] == words[i + 1][k])
            {
                pre.push_back(words[i][j]);
                j++, k++;
            }
            freq[pre.size()]++;
            longestPrefixes.push_back(pre);
        }

        // cout << "printing pairs prefixes" << endl;
        // for(string s : longestPrefixes) cout << s << " " ;
        // cout << endl;

        for (auto i : freq)
            maxHeap.push(i.first);
        // cout << maxHeap.top() << endl;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            // first or last stirng removal
            if (i == 0 || i == n - 1)
            {
                string pre;
                if (i == 0)
                    pre = longestPrefixes[i];
                else
                    pre = longestPrefixes[i - 1];

                // this length is also maximum
                if (pre.size() == maxHeap.top() && freq[maxHeap.top()] == 1)
                {
                    int longest = maxHeap.top();
                    maxHeap.pop();
                    if (!maxHeap.empty())
                        ans.push_back(maxHeap.top());
                    else
                        ans.push_back(0);
                    maxHeap.push(longest);
                }
                // when this length is not maximum -> no effect if remove it
                else
                {
                    ans.push_back(maxHeap.top());
                }
            }
            // i = 1 to n-2
            else
            {
                // pair of {i-1, i} and {i, i+1} will be removed
                // and a new pair {i-1, i+1} will form
                string left = longestPrefixes[i - 1], right = longestPrefixes[i];
                int contribuionLen = max(left.size(), right.size());
                
                int maxLen = INT_MIN;

                // len of this new pair >= maxHeap.top() directly store it
                // len of this new pair < maxHeap.top() -> then check if the string words[i] has only contribution in maxHeap.top()
                // if yes then the len will be max of len and second max of maxHeap
                // if no then store the maxHeap.top()


                string pre = "";
                int j = 0;
                while (j < words[i-1].size() && j < words[i+1].size() && words[i-1][j] == words[i+1][j])
                {
                    pre.push_back(words[i-1][j]);
                    j++;
                }

                // now check those cases
                if(pre.size() >= maxHeap.top()) maxLen = pre.size();
                else{
                    if(contribuionLen == maxHeap.top() && freq[contribuionLen] == 1){
                        int ele = maxHeap.top();
                        maxHeap.pop();
                        maxLen = max((int)pre.size(), maxHeap.top());
                        // again store that maximum element of maxHeap in it
                        maxHeap.push(ele);
                    }
                    else maxLen = maxHeap.top();
                }
                ans.push_back(maxLen);
                
            }
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vs words = {"f","cfe","feab","fcc","cdfda","fcec","afae","cdeb","dc","bffd","edabe"};
    vi ans = sol.longestCommonPrefix(words);
    for (int i : ans)
        cout << i << " ";

    return 0;
}