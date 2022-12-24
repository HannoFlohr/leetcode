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
    void dfs(TreeNode* root, vector<int>& sums, int height) {
        if(root == NULL) return;

        if(sums.size() < height+1)
            sums.push_back(root->val);
        else
            sums[height] += root->val;

        dfs(root->left, sums, height+1);
        dfs(root->right, sums, height+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<int> sums;
        dfs(root, sums, 0);
        return sums.back();
    }
};
//https://leetcode.com/problems/deepest-leaves-sum/