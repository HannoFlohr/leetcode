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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* anchor = new ListNode(1111);
        anchor->next = head;
        
        ListNode* from = anchor;
        ListNode* to = head;
        ListNode* current = NULL;
        ListNode* previous = NULL;
        ListNode* next = NULL;

        while(true) {
            ListNode* node = to;
            for(int i=0; i<k; i++) {
                if(node == NULL) return anchor->next;
                node = node->next;
            }
            
            current = to;
            previous = from;
            for(int i=0; i<k; i++) {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            
            to->next = current;
            from->next = previous;
            from = to;
            to = current;
        }
    }
};
//https://leetcode.com/problems/reverse-nodes-in-k-group/