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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode *cur = head, *next;

        while(cur) {
            next = cur->next;
            while(next && next->val != 0) {
                cur->val += next->val;
                cur->next = next->next;
                next = next->next;
            }

            cur->next = next->next;
            cur = next->next;
        }

        return head;
    }
};
//https://leetcode.com/problems/merge-nodes-in-between-zeros/