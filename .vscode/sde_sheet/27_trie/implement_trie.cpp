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

class Trie
{
public:
    TrieNode* root;
    Trie()
    {   
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* node = root;

        for(char c : word){
            if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }

        node->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode* node = root;

        for(char c : word){
            if(!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode* node = root;

        for(char c : prefix){
            if(!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }

        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}