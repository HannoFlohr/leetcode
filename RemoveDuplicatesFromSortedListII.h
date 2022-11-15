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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head), *before = dummy;
        
        while(head) {
            if(head->next && head->val == head->next->val) {
                while(head->next && head->val == head->next->val)
                    head = head->next;
                
                before->next = head->next;
            }
            else
                before = before->next;
            
            head = head->next;
        }
        
        return dummy->next;
    }
};
//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/