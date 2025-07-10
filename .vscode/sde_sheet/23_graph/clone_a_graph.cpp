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
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> oldToNew;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        Node* first = new Node(node->val);
        oldToNew[node] = first;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node* ngbr : curr->neighbors){
                if(oldToNew.find(ngbr) == oldToNew.end()){
                    Node* newNode = new Node(ngbr->val);
                    q.push(ngbr);
                    oldToNew[ngbr] = newNode;
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[ngbr]);
            }
        }

        return first;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}