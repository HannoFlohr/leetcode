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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> to_remove (nums.begin(), nums.end());
        ListNode dummy (0, head);

        for(ListNode* node = &dummy; node->next != nullptr; ) {
            if(to_remove.contains(node->next->val))
                node->next = node->next->next;
            else
                node = node->next;
        }

        return dummy.next;
    }
};
//https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/