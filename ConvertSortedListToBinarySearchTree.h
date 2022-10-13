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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode *slow=head, *fast=head, *previous=NULL;
        
        //find middle of linked list; after loop fast will point to last node and slow to middle node
        while(fast->next != NULL) {
            fast = fast->next;
            if(fast->next == NULL)
                break;
            
            fast = fast->next;
            previous = slow;
            slow = slow->next;
        }
        
        if(previous != NULL)
            previous->next = NULL;
        else 
            head = NULL;
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/