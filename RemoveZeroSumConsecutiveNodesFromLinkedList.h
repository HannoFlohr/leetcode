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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int,ListNode*> sumsfound_nextnode;
        int sum = 0;

        for(ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            sumsfound_nextnode[sum] = node;
        }

        sum = 0;
        for(ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            node->next = sumsfound_nextnode[sum]->next;
        }
        
        return dummy->next;
    }
};
//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/