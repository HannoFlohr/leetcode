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
    int min_difference = INT_MAX, value = -1;
public:
    int minDiffInBST(TreeNode* root) {
        if(root->left) minDiffInBST(root->left);
        
        if(value >= 0) min_difference = min(min_difference, abs(root->val - value));
        value = root->val;
        
        if(root->right) minDiffInBST(root->right);
        
        return min_difference;
    }
};
//https://leetcode.com/problems/minimum-distance-between-bst-nodes/