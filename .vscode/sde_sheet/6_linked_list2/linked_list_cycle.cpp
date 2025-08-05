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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head) {
        // base case
        if(!head || !head->next) return false;

        ListNode *s = head, *f = head;
        while(f){
            s = s->next;
            f = f->next;
            if(f) f = f->next;
            if(f == s) return true;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}