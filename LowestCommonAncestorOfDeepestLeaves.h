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
    int findLca(TreeNode* node, int depth, int& max_depth, TreeNode*& lca) {
        max_depth = max(max_depth, depth);
        if(node == nullptr)
            return depth;

        int left = findLca(node->left, depth+1, max_depth, lca);
        int right = findLca(node->right, depth+1, max_depth, lca);
        if(left == max_depth && right == max_depth) 
            lca = node;

        return max(left, right);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max_depth = 0;
        TreeNode* lca = nullptr;
        findLca(root, 0, max_depth, lca);
        return lca;
    }
};
//https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/