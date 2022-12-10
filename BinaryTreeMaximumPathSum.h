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
    int max_sum;

    int findMaxPathSum(TreeNode* root) {
        if(!root) return 0;

        int max_left = max(findMaxPathSum(root->left), 0);
        int max_right = max(findMaxPathSum(root->right), 0); 
        int value = root->val + max_left + max_right;
    
        max_sum = max(max_sum, value);
        
        return root->val + max(max_left, max_right);
    }

public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        max_sum = INT_MIN;
        findMaxPathSum(root);
        return max_sum;
    }
};
//https://leetcode.com/problems/binary-tree-maximum-path-sum/