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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1 = headA, *h2 = headB;

        while(h1 && h2){
            h1 = h1->next;
            h2 = h2->next;
        }

        int count = 0;
        if(h1){
            while(h1){
                count++;
                h1 = h1->next;
            }

            h1 = headA, h2 = headB;
            while(count){
                count--;
                h2 = h2->next;
            }

        }
        else{
            while(h2){
                count++;
                h2 = h2->next;
            }
            
            h1 = headA, h2 = headB;
            while(count){
                count--;
                h1 = h1->next;
            }
            
        }
        
        while(h1 && h2){
            if(h1 == h2){
                return h1;
            }
            h1 = h1->next;
            h2 = h2->next;
        }

        return NULL;


        /*
        if(headA == NULL || headB == NULL) return nullptr;
        ListNode* a = headA , *b = headB;
        while(a != b){
            a = a ? a->next : headB ;
            b = b ? b->next : headA ;
        }
        return a;
        */
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}