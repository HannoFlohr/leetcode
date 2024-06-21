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
    bool isUnivalTree(TreeNode* node, int value) {
        if(node == nullptr) {
            return true;
        }
        if(node->val != value) {
            return false;
        }
        return isUnivalTree(node->left, value) && isUnivalTree(node->right, value);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root->val);
    }
};
//https://leetcode.com/problems/univalued-binary-tree/