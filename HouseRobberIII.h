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
    int robTree(TreeNode* root, int& left, int& right) {
        if(root == nullptr) return 0;

        int left_l = 0, left_r = 0, right_l = 0, right_r = 0;
        left = robTree(root->left, left_l, left_r);
        right = robTree(root->right, right_l, right_r);

        return max(root->val + left_l + left_r + right_l + right_r, left + right);
    }

public:
    int rob(TreeNode* root) {
        int left = 0, right = 0;
        return robTree(root, left, right);    
    }
};
//https://leetcode.com/problems/house-robber-iii/