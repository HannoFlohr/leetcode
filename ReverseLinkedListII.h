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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node = new ListNode(0, head);
        ListNode* previous = node;
        
        for(int i=0; i<left-1; i++) previous = previous->next;
        
        ListNode *current = previous->next, *after;
        for(int i=0; i<right-left; i++) {
            after = current->next;
            current->next = after->next;
            after->next = previous->next;
            previous->next = after;
        }
        
        return node->next;
    }
};
//https://leetcode.com/problems/reverse-linked-list-ii/