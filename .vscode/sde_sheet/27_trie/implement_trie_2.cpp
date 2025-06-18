#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;
    bool isEnd;
    int count;
    TrieNode()
    {
        children.resize(26);
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isEnd = false;
        this->count = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
            node->count++;
        }

        node->isEnd = true;
    }

    int countWordsEqualTo(string word)
    {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children[c - 'a'] || node->children[c - 'a']->count == 0) return 0;
            node = node->children[c - 'a'];
        }

        return node->isEnd ? node->count : 0;
    }

    int countWordsStartingWith(string word)
    {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children[c - 'a'] || node->children[c - 'a']->count == 0) return 0;
            node = node->children[c - 'a'];
        }

        return node->count;
    }

    void erase(string word)
    {
        TrieNode* node = root;
        for(char c : word){
            if(!node->children[c - 'a']) return ;
            node = node->children[c - 'a'];
            if(node->count) node->count--;
        }

        return ;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie* trie = new Trie();

    trie->insert("mango");

    cout << trie->countWordsEqualTo("apple") << endl;  // return 0

    trie->insert("app"); 

    trie->erase("apple");
    
    cout << trie->countWordsStartingWith("mango") << endl; // return 1
    return 0;
}