/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int current = 0;
        
        ListNode anchor (0);
        ListNode *node = &anchor;
        
        while(l1 || l2 || current) {
            current += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            
            node->next = new ListNode(current%10);
            node = node->next;
            current /= 10;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return anchor.next;
    }
};
//https://leetcode.com/problems/add-two-numbers/