// Problem description @ https://leetcode.com/problems/reverse-linked-list-ii/
// 24th Feb 2020


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode* cur1 = head;
        ListNode* prev1 = nullptr;
        unsigned int steps = m;
        while (--steps > 0)
        {
            prev1 = cur1;
            cur1 = cur1->next;
        }
        
        ListNode* cur = cur1;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        
        steps = n - m +1;
        while (cur && steps-- > 0)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if (prev1)
            prev1->next = prev;
        else
            head = prev;   
        
        cur1->next = next;
        
        return head;
    }
};