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
    const int MOD = 1e9+7;
    long result = 0, sum = 0;

    int dfs(TreeNode* root) {
        if(!root) return 0;
        int cur_sum = dfs(root->left) + dfs(root->right) + root->val;
        result = max(result, (sum - cur_sum) * cur_sum);
        return cur_sum;
    }

public:
    int maxProduct(TreeNode* root) {
        sum = dfs(root); //compute sum of all nodes 
        dfs(root); //compute sum of each subtree and its complement
        return (int)(result % MOD);
    }
};
//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/