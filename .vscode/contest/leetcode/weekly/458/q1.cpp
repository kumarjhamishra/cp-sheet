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
    string processStr(string s) {
        string ans;

        for(char ch : s){
            if(ch == '*'){
                if(!ans.empty()) ans.pop_back();
            }
            else if(ch == '#'){
                ans += ans;
            }
            else if(ch == '%'){
                reverse(ans.begin(), ans.end());
            }
            else{
                ans.push_back(ch);
            }
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "z*#";
    cout << sol.processStr(s) ;

    return 0;
}