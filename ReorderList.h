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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        
        ListNode *dummy = head, *top;
        
        //put pointers to all nodes in the list on a stack
        stack<ListNode*> nodes;
        while(dummy) {
            nodes.push(dummy);
            dummy = dummy->next;
        }
        
        //insert top of stack between every two nodes starting from the head
        dummy = head;
        int n = nodes.size();
        for(int i=0; i<n/2; i++) {
            top = nodes.top();
            nodes.pop();
            
            top->next = dummy->next;
            dummy->next = top;
            dummy = dummy->next->next;
        }
        
        dummy->next = NULL;
    }
};
//https://leetcode.com/problems/reorder-list/