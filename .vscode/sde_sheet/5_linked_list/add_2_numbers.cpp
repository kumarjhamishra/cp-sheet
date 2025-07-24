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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1, *h2 = l2;
        ListNode *dummy = new ListNode(-1), *head = dummy;
        int rem = 0;
        while(h1 || h2 || rem){
            int sum = 0;
            if(h1){
                sum += h1->val;
                h1 = h1->next;
            }
            if(h2){
                sum += h2->val;
                h2 = h2->next;
            }
            sum += rem;
            int digit = sum % 10;
            rem = sum/10;
            head->next = new ListNode(digit);
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