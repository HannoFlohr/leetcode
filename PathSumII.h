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

vector<vector<int>> result;

void validPaths(TreeNode* root, int sum, vector<int>& path) {
    if(!root) return;
    
    path.push_back(root->val);
    if(!root->left && !root->right && sum == root->val)
        result.push_back(path);
    
    validPaths(root->left, sum-root->val, path);
    validPaths(root->right, sum-root->val, path);
    path.pop_back();
}
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        validPaths(root, targetSum, path);
        return result;
    }
};
//https://leetcode.com/problems/path-sum-ii/