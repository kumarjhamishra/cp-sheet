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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // base cases
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* dummy = new ListNode(-1), *head = dummy;

        ListNode *h1 = list1 , *h2 = list2;
        while(h1 && h2){
            if(h1->val <= h2->val){
                head->next = h1;
                h1 = h1->next;
            }
            else{
                head->next = h2;
                h2 = h2->next;
            }
            head = head->next;
        }

        while(h1){
            head->next = h1;
            h1 = h1->next;
            head = head->next;
        }

        while(h2){
            head->next = h2;
            h2 = h2->next;
            head = head->next;
        }

        return dummy->next;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}