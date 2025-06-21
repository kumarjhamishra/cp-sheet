#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<int, vector<int>> parallelY, parallelX;
        vector<int> x, y;

        for(auto i : coords){
            int xcod = i[0], ycod = i[1];
            x.push_back(xcod);
            y.push_back(ycod);
            
            // in parallel to y -> x cod will be same 
            parallelY[xcod].push_back(ycod);
            parallelX[ycod].push_back(xcod);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll maxArea = -1;
        for(auto i : parallelY){
            if(i.second.size() > 1){
                sort(i.second.begin(), i.second.end());
                int base = i.second.back() - i.second[0];
                int height = max(abs(x.back() - i.first), abs(x[0] - i.first));
                maxArea = max(maxArea, 1ll * base * height);
            }
        }

        for(auto i : parallelX){
            if(i.second.size() > 1){
                sort(i.second.begin(), i.second.end());
                int base = i.second.back() - i.second[0];
                int height = max(abs(y.back() - i.first), abs(y[0] - i.first));
                maxArea = max(maxArea, 1ll * base * height);
            }
        }

        return maxArea != 0 ? maxArea : -1;
        
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<vector<int>> coords = {{1,1},{6,10},{6,5}};
    cout << sol.maxArea(coords);

    return 0;
}

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