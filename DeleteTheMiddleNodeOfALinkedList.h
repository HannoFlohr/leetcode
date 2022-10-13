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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) {
            delete head;
            return NULL;
        }
        
        ListNode *slow = head, *fast = head, *previous=head;
        while(fast && fast->next) {
            if(slow != head)
                previous = previous->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        previous->next = slow->next;
        delete slow;
        
        return head;
    }
};
//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/