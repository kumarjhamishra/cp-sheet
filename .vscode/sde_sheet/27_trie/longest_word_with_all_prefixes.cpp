#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode(){
        children.resize(26);
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
        this->isEnd = false;
    }
};

class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;

        //char last;
        for(char c : word){
            int idx = c - 'a';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
            //last = c;
        }
        
        node->isEnd = true;
        //cout << "in insert last char of word: " << last << " it's end marker: " << node->isEnd << endl;
    }

    bool search(string word){
        TrieNode* node = root;

        for(char c : word){
            int i = c - 'a';
            if(!node->children[i] || !node->children[i]->isEnd) return false;
            node = node->children[i];
        }

        return node->isEnd;
    }
};

class Solution
{
public:
    string completeString(vector<string> &nums)
    {
        Trie* t = new Trie();

        for(string s : nums){
            t->insert(s);
        }

        string ans;
        for(string s : nums){
            if(ans.size() > s.size() || (ans.size() == s.size() && ans <= s)) continue;

            if(t->search(s)) ans = s;
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<string> nums = {"a", "app", "appl", "ap", "apply", "apple"};
    cout << sol.completeString(nums);

    return 0;
}