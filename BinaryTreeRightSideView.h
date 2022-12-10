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
    vector<int> right_side_view;

    void dfs(TreeNode* root, int height) {
        if(!root) return;

        if(right_side_view.size() < height)
            right_side_view.push_back(root->val);

        dfs(root->right, height+1);
        dfs(root->left, height+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        right_side_view.clear();
        dfs(root, 1);
        return right_side_view;
    }
};
//https://leetcode.com/problems/binary-tree-right-side-view/