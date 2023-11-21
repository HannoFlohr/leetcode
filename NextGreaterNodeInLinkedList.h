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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> indices_to_fill, next_largest;
        ListNode* node = head;

        while(node != nullptr) {
            while(indices_to_fill.size() > 0 && next_largest[indices_to_fill.back()] < node->val) {
                next_largest[indices_to_fill.back()] = node->val;
                indices_to_fill.pop_back();
            }

            indices_to_fill.push_back(next_largest.size());
            next_largest.push_back(node->val);

            node = node->next;
        }

        for(int i : indices_to_fill) 
            next_largest[i] = 0;

        return next_largest;
    }
};
//https://leetcode.com/problems/next-greater-node-in-linked-list/