#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;
    int mini0, mini1; 
    // mini0 will be the smallest number which will be having 0 at the ith bit
    // and mini1 will be the smallest number which will be having 1 at the ith bit
    TrieNode()
    {
        children.resize(2);

        for (int i = 0; i < 2; i++)
        {
            this->children[i] = NULL;
        }
        this->mini0 = INT_MAX;
        this->mini1 = INT_MAX;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
            if(bit) node->mini1 = min(node->mini1, num);
            else node->mini0 = min(node->mini0, num);
        }

        return;
    }

    int _xor(int num, int limit)
    {
        TrieNode *node = root;
        //cout << "num: " << num << " limit: " << limit << endl;
        int maxXor = 0, currNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1, oppBit = 1 - bit;
            
            // if this bit is 1 then we want 0 to maximize the xor and the mini0 <= limit then we can go with 0 bit value
            if(bit && node->children[0] && node->children[0]->mini0 <= limit){
                maxXor |= (1 << i);
                node = node->children[0];
            }
            
            // if the bit is 0 then we want 1 with mini1 <= limit to proceed with that value
            else if(!bit && node->children[1] && node->children[1]->mini1 <= limit){
                maxXor |= (1 << i);
                node = node->children[1];
            }

            // bit is 1 but can't proceed with bit 0 so checking for bit 1 
            else if(bit && node->children[1] && node->children[1]->mini1 <= limit){
                // no increment in xor value
                node = node->children[1];
            }

            // bit is 0 but can't proceed with bit 1 so checking for bit 0 
            else if(!bit && node->children[0] && node->children[0]->mini0 <= limit){
                // no increment in xor value
                node = node->children[0];
            }

            // no combination is possible
            else return -1;
        }
        return maxXor;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        Trie* t = new Trie();

        for(int num : nums) t->insert(num);

        vector<int> ans;
        for(auto query : queries){
            int xi = query[0], limit = query[1];
            ans.push_back(t->_xor(xi, limit));
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {536870912,0,534710168,330218644,142254206};
    vector<vector<int>> queries = {{558240772,1000000000},{307628050,1000000000},{3319300,1000000000}, {2751604,683297522},{214004,404207941}};
    Solution sol;
    vector<int> ans = sol.maximizeXor(nums, queries);
    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}