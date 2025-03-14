#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string temp;
            for(int i = 0; i < s.size()-1; i++){
                int num = (s[i] - '0' + s[i+1] - '0')  % 10;
                char n = num + '0';
                temp.push_back(n);
            }
            s = temp;
        }

        return s[0] == s[1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    cout << s.hasSameDigits("3902") << endl;
    cout << s.hasSameDigits("34789") << endl;      
    

    return 0;
}