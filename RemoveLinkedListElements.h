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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        
        ListNode *node;
        while(head!=NULL && head->val==val) {
            node = head;
            head = head->next;
            delete node;
        }
        
        ListNode *current = head;
        while(current && current->next) {
            if(current->next->val == val) {
                node = current->next;
                current->next = current->next->next;
                delete node;
            }
            else
                current = current->next;
        }
        
        return head;
    }
};
//https://leetcode.com/problems/remove-linked-list-elements/