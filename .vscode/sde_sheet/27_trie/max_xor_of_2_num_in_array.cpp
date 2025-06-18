#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode*> children;

    TrieNode()
    {
        children.resize(2);

        for (int i = 0; i < 2; i++)
        {
            this->children[i] = NULL;
        }
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
        //cout << "num: " << num << endl;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1);
            //cout << "i: " << i << " bit: " << bit << endl;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int _xor(int num)
    {
        TrieNode *node = root;
        int max_xor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1), oppBit = 1 - bit;
            if (node->children[oppBit])
            {
                max_xor |= (1 << i);
                node = node->children[oppBit];
            }
            else
            {
                // max_xor |= (0 << i);
                node = node->children[bit];
            }
        }

        return max_xor;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {

        Trie* t = new Trie();
        
        for(int num : nums){
            t->insert(num);
            //cout << "hello" << endl;
        }

        int max_xor = INT_MIN;
        for(int num : nums){
            max_xor = max(max_xor, t->_xor(num));
        }

        return max_xor;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> nums = {14,70,53,83,49,91,36,80,92,51,66,70};
    cout << sol.findMaximumXOR(nums) << endl;

    return 0;
}