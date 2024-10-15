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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* previous = head;
        head = head->next;
        int i = 1;
        vector<int> indices;
        //traverse all nodes and check whether they are local max or min
        //save those indices that are
        while(head->next != nullptr) {
            if((previous->val < head->val && head->val > head->next->val) || 
                (previous->val > head->val && head->val < head->next->val)) {
                    indices.push_back(i);
            }
            previous = head;
            head = head->next;
            ++i;
        }
        //if less than 2 indices were found, no min or max distance can be computed
        if(indices.size() < 2) {
            return {-1,-1};
        }

        //find min distance between the local min/max indices
        int min_distance = INT_MAX;
        for(i = 0; i < indices.size()-1; ++i) {
            min_distance = min(min_distance, indices[i+1] - indices[i]);
        }
        //max distance is last-first index
        return {min_distance, indices.back() - indices[0]};
    }
};
//https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/