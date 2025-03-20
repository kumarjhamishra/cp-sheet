#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    vector<int> longestCommonPrefix(vector<string> &words, int k)
    {
        // base case
        int n = words.size();
        if(n <= k){
            return vector(n, 0);
        }

        unordered_map<string, int> prefix_freq;
        // below map stores the maximum frequency of any prefix of a specific length.
        unordered_map<int, int> max_count, second_max_count;

        for(int i = 0; i < n; i++){
            string prefix;
            for(int j = 0; j < words[i].size(); j++){
                prefix.push_back(words[i][j]);
                                                                                                                                                                                                                                                                                                                                                              
                prefix_freq[prefix]++;

                //The maximum frequency of any prefix of length l
                int l = j + 1;
                if(prefix_freq[prefix] >= max_count[l]){
                    second_max_count[l] = max_count[l];
                    max_count[l] = prefix_freq[prefix];
                }
                else second_max_count[l] = max(second_max_count[l], prefix_freq[prefix]);
            }
        }

        // computation of the longest prefix length which appeared at least k times
        int longest_length = 0;
        for(auto i : max_count){
            if(i.second >= k && i.first > longest_length){
                longest_length = i.first;
            }
        }



        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(words[i].size() < longest_length){
                ans[i] = longest_length;
                continue;
            }

            int len = 0;
            string word = words[i];
            while(!word.empty()){
                int len = word.size();
                if(max_count[len] > k){
                    ans[i] = len;
                    break;
                }
                else if(max_count[len] < k){
                    // check for smaller lengths
                    word.pop_back();
                }
                
                // max_count[len] == k case below

                // now check if the frequency of current prefix is the frequency of longest prefix
                else if(prefix_freq[word] == max_count[len]){
                    if(second_max_count[len] == k){
                        ans[i] = len;
                        break;
                    }
                    // second_max_count[len] < k
                    // means this prefix has made the max_count[len] == k so subtracting it will lead to frequency of k-1 which is not accepted
                    else{
                        word.pop_back();
                    }
                }

                // not a part
                else{
                    ans[i] = len;
                    break;
                }
            }
        }

        return ans;


    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }

    return 0;
}