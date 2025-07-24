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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next){
            return head;
            
        }
        int count = 0;
        ListNode *back = head, *forth = head, *prev = NULL;
        while(forth){
            count++;
            forth = forth->next;
            if(count > n){
                prev = back;
                back = back->next;
            }
        }
        //prev->next = ->next;
        return head;
       
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}