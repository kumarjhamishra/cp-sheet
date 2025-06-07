#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution
{
private:
    ll f(int i, int &n, vector<string> &instructions, vector<int> &values, vector<bool> &visited){
        // base case
        if(i < 0 || i >= n || visited[i]){
            return 0ll;
        }

        visited[i] = true;
        ll score = 0;
        if(instructions[i] == "add") score = values[i] * 1ll + f(i+1, n, instructions, values, visited);
        else score = f(i + values[i], n, instructions, values, visited);

        return score;
    }
public:
    long long calculateScore(vector<string> &instructions, vector<int> &values)
    {
        // index 0 and score 0
        int n = values.size();
        vector<bool> visited(n, false);
        return f(0, n, instructions, values, visited);
    }
};


    int
    main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> instructions = {"jump"};
    vector<int> values = {0};

    Solution sol;
    cout << sol.calculateScore(instructions, values);

    return 0;
}