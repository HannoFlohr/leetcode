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
    int sumRootToLeaf(TreeNode* root, int value = 0) {
        if(root == nullptr) {
            return 0;
        }
        value = value * 2 + root->val;
        
        if(root->left == nullptr && root->right == nullptr) {
            return value;
        }
        return sumRootToLeaf(root->left, value) + sumRootToLeaf(root->right, value);
    }
};
//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/