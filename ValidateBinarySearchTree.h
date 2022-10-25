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
    bool isValid(TreeNode* node, TreeNode* &previous) {
        if(!node) return true;
        if(!isValid(node->left, previous)) return false;
        if(previous && previous->val >= node->val) return false;
        
        previous = node;
        return isValid(node->right, previous);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* previous = NULL;
        return isValid(root, previous);
    }
};
//https://leetcode.com/problems/validate-binary-search-tree/