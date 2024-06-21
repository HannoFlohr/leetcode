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
    ListNode* reverseList(ListNode* head, ListNode *after = NULL, ListNode *before = NULL) {
        if(head == nullptr) 
            return before;
        return reverseList(head->next, (head->next = before, after), head);
    }
};
//https://leetcode.com/problems/reverse-linked-list/