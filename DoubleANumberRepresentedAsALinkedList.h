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
private:
    int doubleTheList(ListNode* node) {
        if(node == nullptr) {
            return 0;
        }

        int new_value = doubleTheList(node->next);
        new_value += node->val * 2;
        node->val = new_value % 10;
        return new_value /= 10;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        int carry = doubleTheList(head);
        return (carry == 0) ? head : new ListNode(carry, head);
    }
};
//https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/