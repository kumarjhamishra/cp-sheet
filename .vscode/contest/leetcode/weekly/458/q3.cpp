#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, long long> pcll;

class Solution {
public:
    char processStr(string s, long long k) {
        vector<pcll> operations;
        ll totalLength = 0;

        
        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                totalLength++;
                operations.push_back({ch, totalLength});
            }
            // remove the last character
            else if(ch == '*'){
                if(totalLength > 0) totalLength--;
                operations.push_back({ch, totalLength});
            }
            // duplicate
            else if(ch == '#'){
                //operations.push_back({ch, totalLength});
                // no need to go beyound k
                //totalLength = min(totalLength * 2, k+1);
                totalLength = totalLength * 2;
                operations.push_back({ch, totalLength});
            }
            // reverse
            else if(ch == '%'){
                // no change in length
                operations.push_back({ch, totalLength});
            }

            if(totalLength > 1ll * 1e15) totalLength = 1ll * 1e15 + 1;

            //cout << "ch: " << ch << " totalLength: " << totalLength << endl;
            //operations.push_back({ch, totalLength});

            //if(totalLength > k) break;
        }

        if(totalLength <= k) return '.';

        //cout << "separation" << endl;
        // process from backwards
        for(int i = operations.size()-1; i >= 0; i--){
            char op = operations[i].first;
            ll currLen = operations[i].second;
            ll prevLen = (i == 0 ? 0 : operations[i-1].second);
            //cout << "op: " << op << " len: " << currLen << endl;
            if(op >= 'a' && op <= 'z'){
                // if k is it last index it, return
                //cout << op << " " << k << endl;
                if(currLen - 1 == k) return op;
            }
            else if(op == '*'){
                // do nothing
                //cout << op << " " << k << endl;
            }
            else if(op == '#'){
                // ll halfLen = currLen/2;
                // if(k >= halfLen) k -= halfLen;
                // cout << op << " " << k << endl;

                //ll prevLen = currLen;
                if(k >= prevLen) k -= prevLen;
            }
            else if(op == '%'){
                k = currLen - k - 1;
                //cout << op << " " << k << endl;
            }
        }

        return '.';
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "z*#";
    ll k = 0;
    cout << sol.processStr(s, k);

    return 0;
}