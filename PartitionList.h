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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left_part = new ListNode(0), *right_part = new ListNode(0);
        ListNode *left_end = left_part, *right_end = right_part;
        
		//loop through nodes; if val of node is < x append to left partition 
		//else to right partition and increment pointers to the end
        while(head) {
            if(head->val < x) {
                left_end->next = head;
                left_end = left_end->next;
            }
            else {
                right_end->next = head;
                right_end = right_end->next;
            }
            
            head = head->next;
        }
        
		//connect partitions and mark end correctly
        left_end->next = right_part->next;
        right_end->next = NULL;
        
        return left_part->next;
    }
};
//https://leetcode.com/problems/partition-list/