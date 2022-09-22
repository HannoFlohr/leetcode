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

int validSum(TreeNode* root, const int& sum, long above) {
    if(!root) return 0;
    long value = above + root->val;
    return (value == sum) + validSum(root->left, sum, value) + validSum(root->right, sum, value); 
}
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        
        return validSum(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum); 
    }
};
//https://leetcode.com/problems/path-sum-iii/