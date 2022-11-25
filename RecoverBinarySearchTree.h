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
private: 
    TreeNode *invalid1 = NULL, *invalid2 = NULL;
    TreeNode *previous = new TreeNode(INT_MIN);
    
    void findInvalids(TreeNode* node) {
        if(!node) return;
        
        findInvalids(node->left);
        
        //check for first invalid
        if(!invalid1 && previous->val > node->val)
            invalid1 = previous;
        //if first was found, check for second
        if(invalid1 && previous->val > node->val)
            invalid2 = node;
        
        previous = node;
        
        findInvalids(node->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        findInvalids(root);
        swap(invalid1->val, invalid2->val);
    }
};
//https://leetcode.com/problems/recover-binary-search-tree/