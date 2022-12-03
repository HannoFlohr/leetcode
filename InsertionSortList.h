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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        
        ListNode* dummy = new ListNode(-5555);
        ListNode *cur = head, *previous = dummy, *next = NULL;
        
        while(cur) {
            next = cur->next;
            
            //find node to insert at
            while(previous->next && previous->next->val < cur->val)
                previous = previous->next;
            
            //insert
            cur->next = previous->next;
            previous->next = cur;
            previous = dummy;
            cur = next;
        }
        
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};
//https://leetcode.com/problems/insertion-sort-list/