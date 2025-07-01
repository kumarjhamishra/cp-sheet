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

class Solution {
public:
    vector<string> partitionString(string s) {
        string segment = "";
        unordered_map<string, bool> seen;
        vector<string> ans;

        for(char ch : s){
            segment.push_back(ch);
            if(seen.find(segment) == seen.end()){
                ans.push_back(segment);
                seen[segment] = true;
                segment = "";
            }
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "abbccccd";
    vector<string> ans = sol.partitionString(s);
    for(string s : ans) cout << s << " ";


    return 0;
}