#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, int> piii;

class Solution
{
private:
    int supportiveFunction(string s)
    {
        s = "1" + s;
        s = s + "1";

        // 1 -> 0 -> 1
        int count1 = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                count1++;
        }

        vector<piii> segmentsOf1;
        unordered_map<int, int> start0, end0;

        int i = 0, continous1 = 0, continous0 = 0, range_start = -1, range_end = -1;
        while (i < n)
        {
            if (s[i] == '1')
            {
                range_start = i;
                while (i < n && s[i] == '1')
                {
                    continous1++;
                    i++;
                }
                range_end = i - 1;
                segmentsOf1.push_back({{range_start, range_end}, continous1});
                continous1 = 0;
            }
            else
            {
                range_start = i;
                while (i < n && s[i] == '0')
                {
                    continous0++;
                    i++;
                }
                range_end = i - 1;
                start0[range_start] = continous0;
                end0[range_end] = continous0;
                continous0 = 0;
            }
        }

        // cout << "printing 1's" << endl;
        // for(auto i : segmentsOf1){
        //     cout << i.first.first << " " << i.first.second << " " << i.second << endl;
        // }

        // cout << "printing start 0's" << endl;
        // for(auto i : start0){
        //     cout << i.first << " " << i.second << endl;
        // }

        // cout << "printing end 0's" << endl;
        // for(auto i : end0){
        //     cout << i.first << " " << i.second << endl;
        // }

        int maxOnes = count1;
        // cout << n << endl;
        for (int i = 1; i < segmentsOf1.size() - 1; i++)
        {
            int st = segmentsOf1[i].first.first, e = segmentsOf1[i].first.second, freq = segmentsOf1[i].second;
            // cout << "st: " << st << " " << "e: " << e << endl;
            // cout << (s[e+1] < n) << endl;
            if (st - 1 >= 0 && s[st - 1] == '0' && e + 1 < n && s[e + 1] == '0')
            {
                // cout << "hello" << endl;
                int newCount = count1;
                newCount += (end0[st - 1] + start0[e + 1]);
                // cout << "new: " << newCount << endl;
                maxOnes = max(maxOnes, newCount);
            }
        }

        return maxOnes - 2;
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries)
    {   
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int s = queries[i][0], e = queries[i][1];
            string sub = s.substr(s, e+1);
            int activeSections = supportiveFunction(sub);
            ans.push_back(activeSections != 0 ? activeSections : 1);
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}