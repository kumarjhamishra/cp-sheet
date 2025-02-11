#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution
{
private:
    vector<ll> pre, prevPosition, prevCount;
    ll count3(string s, ll end){
        ll count = 0;
        for(ll i = 0; i <= end; i++){
            ll sum = pre[end];
            sum -= (i > 0 ? pre[i-1] : 0);
            count += (sum % 3 == 0 ? 1 : 0);
        }

        return count;
    }

    ll count4(string s){
        int n = s.size();
        if(n == 1) return 1;

        int twoDigits = stoi(s.substr(n-2));
        ll count = 0;
        return twoDigits % 4 == 0 ? n : 1;
    }

    ll count6(string s, ll end){
        // any numbers ending at 6 always be divisible by 2 so we only need to check for divisibility with 3
        return count3(s, end);
    }

    ll count7(string s){
        ll n = s.size();
        string temp(n, 7);

        // case of all 7
        if(s == temp) return n;
        
        ll count = 0;
        string num = s;
        for(int i = 0; i < n; i++){
            int nums = stoi(num);
            if(nums % 7 == 0) count++;
            num[i] = '0';
        }

        return count;

    }

    ll count8(string s){
        int n = s.size();
        if(n == 1) return 1;
        if(n == 2){
            return (s == "08" || s == "48" || s == "88") ? 2 : 1;
        }
        ll count = 0;
        int threeDigit = stoi(s.substr(n-3));
        if(threeDigit % 8 == 0){
            count = n;
            if(s != "08" && s!= "48" && s != "88") count -= 1;
            return count;
        }
        
        int twoDigits = stoi(s.substr(n-2));
        if(twoDigits % 8 == 0) return 2;

        return 1;
    }

    ll count9(string s, ll end){
        ll count = 0;
        for(ll i = 0; i <= end; i++){
            ll sum = pre[end];
            sum -= (i > 0 ? pre[i-1] : 0);
            count += (sum % 9 == 0 ? 1 : 0);
        }

        return count;
    }
public:
    long long countSubstrings(string& s)
    {  
       
        ll n = s.size(), i = 0, j = 0, count = 0;
        pre.resize(n, 0);
        prevPosition.resize(n, -1);
        prevCount.resize(n, 0);
        
        for(; j < n; j++){
            pre[j] = s[j] - '0';
            if(j > 0) pre[j] += pre[j-1];

            if(s[j] == '0'){
                continue;
            }
            else if(s[j] == '1' || s[j] == '2' || s[j] == '5'){
                count += 1ll * (j + 1);
            }
            else if(s[j] == '3'){
                count += 1ll * count3(s.substr(i, j+1), j);
            }
            else if(s[j] == '4'){
                count += 1ll * count4(s.substr(i, j+1));
            }
            else if(s[j] == '6'){
                count += 1ll * count6(s.substr(i, j+1), j);
            }
            else if(s[j] == '7'){
                count += 1ll * count7(s.substr(i, j+1));
            }
            else if(s[j] == '8'){
                count += 1ll * count8(s.substr(i, j+1));
            }
            else{
                count += 1ll * count9(s.substr(i, j+1), j);
            }
            
        }

        return count;
    }
};

int
main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "5701283";
    Solution sol;
    cout << sol.countSubstrings(s) << endl;

    return 0;
}