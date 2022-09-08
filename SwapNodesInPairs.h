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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newHead;
        newHead = head->next;
        
        //recursively swap next pairs
        head->next = swapPairs(head->next->next); 
        
        newHead->next = head;
        return newHead;
    }
};
//https://leetcode.com/problems/swap-nodes-in-pairs/