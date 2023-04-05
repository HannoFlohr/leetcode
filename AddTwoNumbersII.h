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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> values1, values2;

        while(l1 != nullptr) {
            values1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            values2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *node, *nextNode = nullptr;
        int value, carry = 0;
        while(!values1.empty() || !values2.empty() || carry > 0) {
            value = carry;
            if(!values1.empty()) {
                value += values1.top();
                values1.pop();
            }
            if(!values2.empty()) {
                value += values2.top();
                values2.pop();
            }

            node = new ListNode(value);
            carry = node->val >= 10;
            node->val %= 10;
            node->next = nextNode;
        
            nextNode = node;
        }

        return node;
    }
};
//https://leetcode.com/problems/add-two-numbers-ii/