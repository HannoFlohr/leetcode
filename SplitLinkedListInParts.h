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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> split_list (k, nullptr); 
        ListNode *node = head, *end_part = nullptr;

        int total_nodes = 0;
        while(node != nullptr) {
            ++total_nodes;
            node = node->next;
        }

        int items_per_part = total_nodes / k;
        int extra_item = total_nodes % k; 

        node = head;
        for(int insert_index = 0; node != nullptr && insert_index < k; ++insert_index, --extra_item) {
            split_list[insert_index] = node;

            for(int j = 0; j < items_per_part+(extra_item > 0); ++j) {
                end_part = node;
                node = node->next;
            }

            end_part->next = nullptr;
        }

        return split_list;
    }
};
//https://leetcode.com/problems/split-linked-list-in-parts/