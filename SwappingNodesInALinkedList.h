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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *node1 = head, *node2 = head, *kthNode = nullptr;

        //find kth node of list
        while(--k) 
            node1 = node1->next;
        kthNode = node1;

        node1 = node1->next;

        //node2 is at head, node1 at element after kth
        //go to next element until node1 reaches end, than node2 will be at kth last element
        while(node1 != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
        }

        swap(kthNode->val, node2->val);

        return head;
    }
};
//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/