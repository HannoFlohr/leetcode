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
    TreeNode* increasingBST(TreeNode* root, TreeNode* parent=nullptr) {
        if(root == nullptr) return parent;
    
        TreeNode* node = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, parent);

        return node;
    }
};
//https://leetcode.com/problems/increasing-order-search-tree/